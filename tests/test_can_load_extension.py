from .common import fresh, sqlite3

def test_does_load():
    db = fresh()
    assert isinstance(db, sqlite3.Connection)

def test_convert_origin_to_h3():
    db = fresh()
    cur = db.execute("Select h3FromLatLan(0, 0, 10);")
    assert cur.fetchall() == [(623560421467684863,)]


def test_convert_origin_to_h3_string():
    db = fresh()
    cur = db.execute("Select h3ToString(h3FromLatLan(0, 0, 10));")
    assert cur.fetchall() == [("8a754e64992ffff",)]

