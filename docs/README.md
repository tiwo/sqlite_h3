# sqlite_h3 ⬡‿⬠

An SQLite extension for working with geographic data in the [H3 global grid](https://h3geo.org/).


### Usage

You'll need only the stand-alone `sqlite_h3.so`. You can load this extension from within SQLite, for example from SQLite's command-line interface via:

    SQLite version 3.31.1 2020-01-27 19:55:54
    sqlite> .load dist/sqlite_h3.so

or via the API you're using (for example, [`load_extension`](https://www.sqlite.org/c3ref/load_extension.html) from C, [`enable_load_extension`/`load_extension`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Connection.load_extension) from Python).



### License

Copyright © 2022 Thomas Wissen
    
Licensed under the **Apache License**, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    
http://www.apache.org/licenses/LICENSE-2.0
    
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.