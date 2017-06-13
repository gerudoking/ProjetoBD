DELIMITER $$

CREATE TRIGGER cobrmotr AFTER INSERT
ON cobrador
FOR EACH ROW
BEGIN
	INSERT INTO empregado_emp_trans VALUES (id, 'indefinido', CPF, RG, `Órgão expedidor`);
END$$

DELIMITER ;