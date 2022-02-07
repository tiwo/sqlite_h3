#include <stddef.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT1

#include <h3api.h>


static void latLng_to_h3(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
    double lat = sqlite3_value_double(argv[0]);
    double lng = sqlite3_value_double(argv[1]);
    int res = sqlite3_value_int(argv[2]);

    fprintf(stderr, "latLng_to_h3: lat=%f, lng=%f, res=%d\n", lat, lng, res);

    LatLng geo = {.lat=lat, .lng=lng};
    H3Index cell;
    H3Error error = latLngToCell(&geo, res, &cell);

    fprintf(stderr, "  result: error=%d, cell=%"PRIu64"\n", error, cell);

    if (error) {
        sqlite3_result_null(ctx);
        return;
    }

    sqlite3_result_int64(ctx, (int64_t)cell);
}


static void cellToString(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
  // H3Error H3_EXPORT(h3ToString)(H3Index h, char *str, size_t sz);

  H3Index cell = (uint64_t)sqlite3_value_int64(argv[0]);

  char result[17];
  H3Error error = h3ToString(cell, result, 17);
  if (error) {
    sqlite3_result_null(ctx);
    return;
  }

  sqlite3_result_text(ctx, result, -1, SQLITE_TRANSIENT);
}



#ifdef _WIN32
__declspec(dllexport)
#endif


int sqlite3_sqliteh_init(sqlite3 *db,  char **pzErrMsg, const sqlite3_api_routines *pApi
){
  SQLITE_EXTENSION_INIT2(pApi);

  int error = SQLITE_OK;

  const int innoc = SQLITE_UTF8 | SQLITE_DETERMINISTIC | SQLITE_INNOCUOUS;

  error = sqlite3_create_function(db, "h3FromLatLan",   3, innoc, NULL, latLng_to_h3, NULL, NULL); if (error != SQLITE_OK) { return error; }
  error = sqlite3_create_function(db, "h3ToString",     1, innoc, NULL, cellToString, NULL, NULL); if (error != SQLITE_OK) { return error; }

  return SQLITE_OK;
}