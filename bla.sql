-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Erstellungszeit: 12. Mrz 2015 um 15:26
-- Server Version: 5.6.21
-- PHP-Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Datenbank: `test`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `personen`
--

CREATE TABLE IF NOT EXISTS `personen` (
    `ID` int(20) NOT NULL,
      `Name` varchar(128) NOT NULL,
        `Vorname` varchar(128) NOT NULL,
          `LetzterBesuch` date NOT NULL,
            `PersonenTyp` varchar(20) NOT NULL
            ) ENGINE=InnoDB DEFAULT CHARSET=latin1;

            --
-- Daten für Tabelle `personen`
--

INSERT INTO `personen` (`ID`, `Name`, `Vorname`, `LetzterBesuch`, `PersonenTyp`) VALUES
(1, 'Drechsler', 'Heinz', '2015-03-02', 'Patient'),
(2, 'Müller', 'Peter', '2000-01-10', 'Mitarbeiter'),
(3, 'Lüders', 'Fritz', '2015-02-09', 'patient'),
(4, 'Ziehzahn', 'Hans', '1999-12-12', 'mitarbeiter');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
