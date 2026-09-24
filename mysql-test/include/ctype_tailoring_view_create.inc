# Create a test view similar to mysql.user, which caused MDEV-41246:
# a latin1_swedish_ci column with the narrow repertoire ASCII_ALNUM,
# calculated by IF() from two literals. It always has exactly one row, 'Y'.
# The current client/connection character sets are preserved.
# The view is dropped by ctype_tailoring_view_drop.inc.

--disable_query_log
SET @ctype_tailoring_save_client= @@character_set_client;
SET @ctype_tailoring_save_results= @@character_set_results;
SET @ctype_tailoring_save_collation= @@collation_connection;
SET NAMES latin1 COLLATE latin1_swedish_ci;
CREATE TABLE t_tailoring (a INT);
INSERT INTO t_tailoring VALUES (1);
CREATE VIEW v_tailoring AS SELECT IF(a=1,'Y','N') AS c FROM t_tailoring;
SET @@character_set_client= @ctype_tailoring_save_client;
SET @@character_set_results= @ctype_tailoring_save_results;
SET @@collation_connection= @ctype_tailoring_save_collation;
--enable_query_log
