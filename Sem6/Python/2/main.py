import sqlite3

con = sqlite3.connect('db01.db')

# con.open()

cur = con.cursor()

cur.execute('DROP TABLE IF EXISTS books')

cur.execute('''CREATE TABLE books
            (id INTEGER PRIMARY KEY,
            title VARCHAR(30),
            author VARCHAR(30),
            pers TEXT)''')

cur.execute('''CREATE TABLE IF NOT EXISTS books
            (id INTEGER PRIMARY KEY,
            title VARCHAR(30),
            author VARCHAR(30),
            pers TEXT)''')

print(cur.lastrowid)
cur.execute('SELECT * FROM books')
print(cur.fetchall())

var1 = ("Роман",)
var2 = (2, "Рассказ")
var3 = {"id": 3, "name": "Стихотворение"}

sql1 = '''INSERT INTO publication (name_publications) VALUES(?)'''
sql2 = '''INSERT INTO publication VALUES(?,?)'''
sql3 = '''INSERT INTO publication VALUES(:id,:name)'''

cur.execute(sql1, var1)
cur.execute(sql2, var2)
cur.execute(sql3, var3)
con.commit()

print(cur.lastrowid)
cur.execute('SELECT * FROM books')
print(cur.fetchall())

con.close()
