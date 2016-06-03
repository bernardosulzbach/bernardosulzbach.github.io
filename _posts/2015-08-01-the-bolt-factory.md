---
layout: post
title: "The Bolt Factory"
---

This is my solution to a problem called The Bolt Factory. The problem statement follows

> In a bolt factory, machines A, B, and C manufacture 25%, 35%, and 40% of the total output,
and have defective rates of 5%, 4%, and 2%, respectively. A bolt is chosen at random and is found to be defective.
What are the probabilities that it was manufactured by each of the three machines?

This is a simple Bayes' theorem problem.
Let P(A), P(B), and P(C) denote the probability of the bolt being produced by A, B, and C, respectively.
Let also P(D) indicate the probability of the bolt being defective.
I will only calculate the probability of the defective bolt being manufactured by A and B with the theorem
as the defective bolt must have been produced by one of the machines and, therefore,

    P(A|D) + P(B|D) +  P(C|D) = 1

what makes calculating `P(C|D)` with the theorem unnecessary.

P(D) will be calculated beforehand to speed things up. By the total probability theorem, it is known that

    P(D) = P(D|A)P(A) + P(D|B)P(B) + P(D|C)P(C)
         = (.05)(.25) + (.04)(.35) + (.02)(.4)
         = .0345

    P(A|D) = P(D|A)P(A) / P(D) = (.05)(.25) / (.0345) ~= 0.3623
    P(B|D) = P(D|B)P(B) / P(D) = (.04)(.35) / (.0345) ~= 0.4058
    P(C|D) ~= 1 - 0.3623 - 0.4058 = 0.2319
