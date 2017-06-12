CREATE 
    ALGORITHM = UNDEFINED 
    DEFINER = `root`@`localhost` 
    SQL SECURITY DEFINER
VIEW `viasdf` AS
    SELECT 
        `via`.`id` AS `id`,
        `via`.`Identificação` AS `Identificação`
    FROM
        `via`
    WHERE
        (`via`.`UF` = 'DF')