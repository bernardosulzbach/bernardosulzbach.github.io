#!/usr/bin/env python3

# As a script-wise convention, a huge list of complaints is built recursively and printed when finished.

import os
import re


def get_file_list():
    folder = os.path.dirname(__file__)
    project_root = os.path.join(folder, '..')
    file_list = []
    os.chdir(project_root)
    for root, _, files in os.walk(os.curdir):
        for file in files:
            if file.endswith('.md'):
                file_list.append(os.path.join(root, file))
    file_list = sorted(file_list)
    return file_list


def lint_markdown(lines, filename, markdown):
    """
    Lints the markdown passed.
    :param lines: the list of output lines
    :param filename: the name of the file for output
    :param markdown: the markdown read
    """
    if filename.split('/')[-1] in ('LICENSE.md', 'README.md'):
        return
    issues = check_preamble(markdown)
    issue_count = len(issues)
    if issue_count > 0:
        noun = 'issue' if issue_count == 1 else 'issues'
        lines.append('Got {} {} in {}:'.format(issue_count, noun, filename))
        lines.extend(['  ' + complaint for complaint in issues])


def check_preamble(text):
    complaints = []
    lines = text.split('\n')
    if len(lines) < 4:
        complaints.append('Preamble is too short')
    else:
        if not re.match("\-\-\-", lines[0]):
            complaints.append('Line 1: expected "---" but got "{}" instead'.format(lines[0]))
        if not re.match("layout: ", lines[1]):
            complaints.append('Line 2: expected layout but got "{}" instead'.format(lines[1]))
        if not re.match("title: ", lines[2]):
            complaints.append('Line 3: expected title but got "{}" instead'.format(lines[2]))
        if not re.match("tags: \[.*\]|\-\-\-", lines[3]):
            complaints.append('Line 4: got invalid line "{}"'.format(lines[3]))
    return complaints


def main():
    output = []
    files = get_file_list()
    for filename in files:
        with open(filename) as f:
            lint_markdown(output, f.name, f.read())
    if len(output) == 0:
        print('Everything is fine with the ' + str(len(files)) + ' files checked.')
    else:
        print('\n'.join(output))


if __name__ == '__main__':
    main()
