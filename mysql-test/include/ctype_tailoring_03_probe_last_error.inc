SELECT c FROM v_tailoring WHERE c='Y';
SELECT c FROM v_tailoring WHERE c<>'Y_';
--error ER_CANT_AGGREGATE_2COLLATIONS
SELECT c FROM v_tailoring WHERE c<>'Y+';
