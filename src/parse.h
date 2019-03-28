/* Copyright 2019 Joshua Nelson
 * This program is licensed under the BSD 3-Clause License.
 * See LICENSE.txt or https://opensource.org/licenses/BSD-3-Clause for details.
 */
#ifndef PARSE_H
#define PARSE_H
#include "dict.h"

enum method {
  GET, HEAD, NOT_RECOGNIZED, ERROR
};

struct request_info {
  enum method method;
  const char *url;
  const char *version;
};

DICT get_all_mimetypes(void);
struct request_info process_request_line(const char**);
DICT process_headers(const char**);
const char *get_mimetype(const char *const);
#endif  // PARSE_H
