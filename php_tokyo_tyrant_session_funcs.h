/*
  +----------------------------------------------------------------------+
  | PHP Version 5 / Tokyo tyrant                                         |
  +----------------------------------------------------------------------+
  | Copyright (c) 2009 Mikko Koppanen                                    |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Mikko Koppanen <mkoppanen@php.net>                          |
  +----------------------------------------------------------------------+
*/
#ifndef _PHP_TOKYO_TYRANT_SESSION_FUNCS_H_
# define _PHP_TOKYO_TYRANT_SESSION_FUNCS_H_

php_tt_session *php_tt_session_init(TSRMLS_D);

void php_tt_session_deinit(php_tt_session *session TSRMLS_DC);

char *php_tt_checksum(char *sess_rand, int idx, char *pk, char *salt TSRMLS_DC);

char *php_tt_create_sid(char *sess_rand, int idx, char *pk, char *salt TSRMLS_DC);

char *php_tt_create_pk(php_tt_conn *conn, int *pk_len TSRMLS_DC);

zend_bool php_tt_tokenize(char *session_id, char **sess_rand, char **checksum, int *idx, char **pk_str TSRMLS_DC);

zend_bool php_tt_validate(char *sess_rand, char *checksum, int idx, char *pk, char *salt TSRMLS_DC);

char *php_tt_get_sess_data(php_tt_conn *conn, char *sess_rand, const char *pk, int pk_len, int *data_len, zend_bool *mismatch TSRMLS_DC);

zend_bool php_tt_save_sess_data(php_tt_conn *conn, char *rand_part, char *pk, int pk_len, const char *data, int data_len TSRMLS_DC);

zend_bool php_tt_sess_touch(php_tt_conn *conn, char *current_rand, char *sess_rand, char *pk, int pk_len TSRMLS_DC);

zend_bool php_tt_sess_destroy(php_tt_conn *conn, char *pk, int pk_len TSRMLS_DC);

#endif
