import time

import psycopg2

TRIALS = 100

if __name__ == '__main__':
    with psycopg2.connect("dbname=test user=bernardo") as connection:
        cursor = connection.cursor()
        cursor.execute("DROP TABLE IF EXISTS integer")
        cursor.execute("CREATE TABLE integer (id serial PRIMARY KEY)")
        cursor.execute("CREATE INDEX ON integer (id)")
        steps = [10 ** i for i in range(1, 8)]


        def profile_query(query):
            begin = time.time()
            for _ in range(TRIALS):
                cursor.execute(query)
            return (time.time() - begin) / TRIALS


        a_query = 'SELECT * FROM integer ORDER BY random() LIMIT 1'
        b_query = 'SELECT * FROM integer ORDER BY id LIMIT 1 OFFSET floor(random() * (SELECT count(*) FROM integer))'
        a_time = []
        b_time = []
        for i, step in enumerate(steps):
            for _ in range(step - (0 if i == 0 else steps[i - 1])):
                cursor.execute('INSERT INTO integer DEFAULT VALUES')
            connection.commit()
            a_time.append(profile_query(a_query))
            b_time.append(profile_query(b_query))
        for i in range(len(steps)):
            print("{:-10,} | {:-8.3f} ms | {:-8.3f} ms ".format(steps[i], 1000 * a_time[i], 1000 * b_time[i]))
