-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: transporte
-- ------------------------------------------------------
-- Server version	5.7.18-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `categoria_veiculo`
--

DROP TABLE IF EXISTS `categoria_veiculo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `categoria_veiculo` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) NOT NULL,
  `Número de rodas` int(10) unsigned NOT NULL,
  `Tração` varchar(45) NOT NULL,
  `Tipo` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `Nome_UNIQUE` (`Nome`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `categoria_veiculo`
--

LOCK TABLES `categoria_veiculo` WRITE;
/*!40000 ALTER TABLE `categoria_veiculo` DISABLE KEYS */;
INSERT INTO `categoria_veiculo` VALUES (1,'Ç…',2,'X','B');
/*!40000 ALTER TABLE `categoria_veiculo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cobrador`
--

DROP TABLE IF EXISTS `cobrador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cobrador` (
  `id` int(10) unsigned NOT NULL DEFAULT '99999',
  `Escolaridade` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cobrador`
--

LOCK TABLES `cobrador` WRITE;
/*!40000 ALTER TABLE `cobrador` DISABLE KEYS */;
INSERT INTO `cobrador` VALUES (99999,'Superior');
/*!40000 ALTER TABLE `cobrador` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `condutor`
--

DROP TABLE IF EXISTS `condutor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `condutor` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome` varchar(200) NOT NULL,
  `CPF` int(10) unsigned NOT NULL,
  `RG` int(11) NOT NULL,
  `Órgão Expedidor` varchar(45) NOT NULL,
  `Data de nascimento` date NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `CPF_UNIQUE` (`CPF`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `condutor`
--

LOCK TABLES `condutor` WRITE;
/*!40000 ALTER TABLE `condutor` DISABLE KEYS */;
INSERT INTO `condutor` VALUES (4,'Jos‚',22,33,'SSP-DF','1995-04-05'),(5,'José',34,45,'SSP-AC','1991-11-11');
/*!40000 ALTER TABLE `condutor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `empregado_emp_trans`
--

DROP TABLE IF EXISTS `empregado_emp_trans`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `empregado_emp_trans` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome` varchar(200) NOT NULL,
  `CPF` int(10) unsigned NOT NULL,
  `RG` int(10) unsigned NOT NULL,
  `Órgão expedidor` varchar(45) NOT NULL,
  `Data de nascimento` date NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idempregados_UNIQUE` (`id`),
  UNIQUE KEY `CPF_UNIQUE` (`CPF`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empregado_emp_trans`
--

LOCK TABLES `empregado_emp_trans` WRITE;
/*!40000 ALTER TABLE `empregado_emp_trans` DISABLE KEYS */;
/*!40000 ALTER TABLE `empregado_emp_trans` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER insere_cobrador_apos_empregado AFTER INSERT
ON empregado_emp_trans
FOR EACH ROW
BEGIN
	INSERT INTO cobrador (`id`) VALUES (new.id);
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `empresa_transporte`
--

DROP TABLE IF EXISTS `empresa_transporte`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `empresa_transporte` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome Comercial` varchar(45) NOT NULL,
  `Nome Fantasia` varchar(45) DEFAULT NULL,
  `Tipo` varchar(45) NOT NULL,
  `Sede` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `Nome Comercial_UNIQUE` (`Nome Comercial`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empresa_transporte`
--

LOCK TABLES `empresa_transporte` WRITE;
/*!40000 ALTER TABLE `empresa_transporte` DISABLE KEYS */;
/*!40000 ALTER TABLE `empresa_transporte` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `fiscalizacao`
--

DROP TABLE IF EXISTS `fiscalizacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `fiscalizacao` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `fiscalizacao`
--

LOCK TABLES `fiscalizacao` WRITE;
/*!40000 ALTER TABLE `fiscalizacao` DISABLE KEYS */;
/*!40000 ALTER TABLE `fiscalizacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `funcionario_orgao`
--

DROP TABLE IF EXISTS `funcionario_orgao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `funcionario_orgao` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) NOT NULL,
  `CPF` int(10) unsigned NOT NULL,
  `RG` int(10) unsigned NOT NULL,
  `Órgão expedidor` varchar(45) NOT NULL,
  `Função` varchar(45) NOT NULL,
  `idÓrgãoTrânsito` int(10) unsigned NOT NULL,
  `Data de nascimento` date NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `CPF_UNIQUE` (`CPF`),
  KEY `idOrgTran_idx` (`idÓrgãoTrânsito`),
  CONSTRAINT `idOrgTran` FOREIGN KEY (`idÓrgãoTrânsito`) REFERENCES `orgao_transito` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `funcionario_orgao`
--

LOCK TABLES `funcionario_orgao` WRITE;
/*!40000 ALTER TABLE `funcionario_orgao` DISABLE KEYS */;
/*!40000 ALTER TABLE `funcionario_orgao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `habilitacao`
--

DROP TABLE IF EXISTS `habilitacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `habilitacao` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Número` int(10) unsigned NOT NULL,
  `Validade` date NOT NULL,
  `Categoria` varchar(2) NOT NULL,
  `UF` varchar(2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `Número_UNIQUE` (`Número`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `habilitacao`
--

LOCK TABLES `habilitacao` WRITE;
/*!40000 ALTER TABLE `habilitacao` DISABLE KEYS */;
/*!40000 ALTER TABLE `habilitacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `infracao`
--

DROP TABLE IF EXISTS `infracao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `infracao` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Situação` varchar(45) NOT NULL,
  `Data` date NOT NULL,
  `Vencimento` date NOT NULL,
  `Velocidade Aferida` int(3) unsigned DEFAULT NULL,
  `idCondutor` int(10) unsigned NOT NULL,
  `idTipoInfracao` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `idCondutor_idx` (`idCondutor`),
  KEY `idTipoInfr_idx` (`idTipoInfracao`),
  CONSTRAINT `idCond` FOREIGN KEY (`idCondutor`) REFERENCES `condutor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `idTipoInfr` FOREIGN KEY (`idTipoInfracao`) REFERENCES `tipo_infracao` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `infracao`
--

LOCK TABLES `infracao` WRITE;
/*!40000 ALTER TABLE `infracao` DISABLE KEYS */;
/*!40000 ALTER TABLE `infracao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `local`
--

DROP TABLE IF EXISTS `local`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `local` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) NOT NULL,
  `Descrição` varchar(300) DEFAULT NULL,
  `CEP` int(8) DEFAULT NULL,
  `Tipo` varchar(45) DEFAULT NULL,
  `UF` varchar(2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idlocal_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `local`
--

LOCK TABLES `local` WRITE;
/*!40000 ALTER TABLE `local` DISABLE KEYS */;
/*!40000 ALTER TABLE `local` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `marca_veiculo`
--

DROP TABLE IF EXISTS `marca_veiculo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `marca_veiculo` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome Comercial` varchar(45) NOT NULL,
  `Nome Fantasia` varchar(45) DEFAULT NULL,
  `Tipo` varchar(45) NOT NULL,
  `Sede` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `jd_UNIQUE` (`id`),
  UNIQUE KEY `Nome Comercial_UNIQUE` (`Nome Comercial`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `marca_veiculo`
--

LOCK TABLES `marca_veiculo` WRITE;
/*!40000 ALTER TABLE `marca_veiculo` DISABLE KEYS */;
/*!40000 ALTER TABLE `marca_veiculo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `motorista`
--

DROP TABLE IF EXISTS `motorista`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `motorista` (
  `id` int(10) unsigned NOT NULL,
  `CNH` int(10) unsigned NOT NULL,
  `Validade CNH` date NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idmotorista_UNIQUE` (`id`),
  UNIQUE KEY `CNH_UNIQUE` (`CNH`),
  CONSTRAINT `idMotorista` FOREIGN KEY (`id`) REFERENCES `empregado_emp_trans` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `motorista`
--

LOCK TABLES `motorista` WRITE;
/*!40000 ALTER TABLE `motorista` DISABLE KEYS */;
/*!40000 ALTER TABLE `motorista` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orgao_transito`
--

DROP TABLE IF EXISTS `orgao_transito`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orgao_transito` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) NOT NULL,
  `Descrição` varchar(300) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `Nome_UNIQUE` (`Nome`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orgao_transito`
--

LOCK TABLES `orgao_transito` WRITE;
/*!40000 ALTER TABLE `orgao_transito` DISABLE KEYS */;
/*!40000 ALTER TABLE `orgao_transito` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sinalizacao`
--

DROP TABLE IF EXISTS `sinalizacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sinalizacao` (
  `id` int(10) unsigned NOT NULL,
  `Descrição` varchar(300) NOT NULL,
  `Tipo` varchar(45) NOT NULL,
  `idVia` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `idVi_idx` (`idVia`),
  CONSTRAINT `idVi` FOREIGN KEY (`idVia`) REFERENCES `via` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sinalizacao`
--

LOCK TABLES `sinalizacao` WRITE;
/*!40000 ALTER TABLE `sinalizacao` DISABLE KEYS */;
/*!40000 ALTER TABLE `sinalizacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `telefone_empregado`
--

DROP TABLE IF EXISTS `telefone_empregado`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `telefone_empregado` (
  `id` int(10) unsigned NOT NULL,
  `Telefone` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `idEmpregado` FOREIGN KEY (`id`) REFERENCES `empregado_emp_trans` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `telefone_empregado`
--

LOCK TABLES `telefone_empregado` WRITE;
/*!40000 ALTER TABLE `telefone_empregado` DISABLE KEYS */;
/*!40000 ALTER TABLE `telefone_empregado` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tipo_infracao`
--

DROP TABLE IF EXISTS `tipo_infracao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tipo_infracao` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Descrição` varchar(300) NOT NULL,
  `Classificação` varchar(11) NOT NULL,
  `Pontuação` int(1) unsigned NOT NULL,
  `Valor` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tipo_infracao`
--

LOCK TABLES `tipo_infracao` WRITE;
/*!40000 ALTER TABLE `tipo_infracao` DISABLE KEYS */;
/*!40000 ALTER TABLE `tipo_infracao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `veiculo`
--

DROP TABLE IF EXISTS `veiculo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `veiculo` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Placa` varchar(45) DEFAULT NULL,
  `Chassi` varchar(45) NOT NULL,
  `idEmpresa` int(10) unsigned DEFAULT NULL,
  `idCondutor` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `Chassi_UNIQUE` (`Chassi`),
  UNIQUE KEY `Placa_UNIQUE` (`Placa`),
  KEY `idEmp_idx` (`idEmpresa`),
  KEY `idCondutor_idx` (`idCondutor`),
  CONSTRAINT `idCondutor` FOREIGN KEY (`idCondutor`) REFERENCES `condutor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `idEmpresa` FOREIGN KEY (`idEmpresa`) REFERENCES `empresa_transporte` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `veiculo`
--

LOCK TABLES `veiculo` WRITE;
/*!40000 ALTER TABLE `veiculo` DISABLE KEYS */;
/*!40000 ALTER TABLE `veiculo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `via`
--

DROP TABLE IF EXISTS `via`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `via` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Identificação` int(10) unsigned NOT NULL,
  `Velocidade` int(3) unsigned DEFAULT NULL,
  `Classificação` varchar(45) NOT NULL,
  `UF` varchar(2) NOT NULL,
  `idLocal` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `idLoc_idx` (`idLocal`),
  CONSTRAINT `idLoc` FOREIGN KEY (`idLocal`) REFERENCES `local` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `via`
--

LOCK TABLES `via` WRITE;
/*!40000 ALTER TABLE `via` DISABLE KEYS */;
/*!40000 ALTER TABLE `via` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `viasdf`
--

DROP TABLE IF EXISTS `viasdf`;
/*!50001 DROP VIEW IF EXISTS `viasdf`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `viasdf` AS SELECT 
 1 AS `id`,
 1 AS `Identificação`*/;
SET character_set_client = @saved_cs_client;

--
-- Dumping events for database 'transporte'
--

--
-- Final view structure for view `viasdf`
--

/*!50001 DROP VIEW IF EXISTS `viasdf`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `viasdf` AS select `via`.`id` AS `id`,`via`.`Identificação` AS `Identificação` from `via` where (`via`.`UF` = 'DF') */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-06-14 13:41:53
