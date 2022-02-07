import sqlite3

def fresh():
    db = sqlite3.connect(":memory:")
    db.enable_load_extension(True)
    db.load_extension("../dist/sqlite_h3.so")
    return db
    