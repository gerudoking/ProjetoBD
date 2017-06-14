DELIMITER $$

CREATE TRIGGER insere_cobrador_apos_empregado AFTER INSERT
ON empregado_emp_trans
FOR EACH ROW
BEGIN
	INSERT INTO cobrador (`id`) VALUES (new.id);
END$$

DELIMITER ;