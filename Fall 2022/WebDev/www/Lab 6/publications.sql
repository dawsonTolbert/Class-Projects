-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 18, 2022 at 05:24 AM
-- Server version: 8.0.30
-- PHP Version: 7.4.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `publications`
--

-- --------------------------------------------------------

--
-- Table structure for table `albums`
--

CREATE TABLE `albums` (
  `artist` varchar(128) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `title` varchar(128) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `year` char(4) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `rating` int NOT NULL,
  `stock` varchar(3) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `albums`
--

INSERT INTO `albums` (`artist`, `title`, `year`, `rating`, `stock`) VALUES
('Radiohead', 'OK Computer', '1997', 0, 'Yes'),
('Radiohed', 'Kid A', '2000', 0, 'Yes'),
('System of a Down', 'Toxicity', '2001', 0, 'Yes'),
('Swans', 'To Be Kind', '2014', 0, 'Yes'),
('Frank Ocean', 'Blonde', '2016', 0, 'No'),
('JPEGMAFIA', 'Veteran', '2018', 0, 'Yes'),
('The Microphones', 'The Glow Pt. 2', '2001', 0, 'Yes'),
('Ricky Eat Acid', 'Seeing Little Ghosts Everywhere', '2011', 0, 'Yes'),
('Mount Eerie', 'A Crow Looked at Me', '2017', 5, 'No'),
('clipping.', 'There Existed an Addiction to Blood', '2019', 5, 'Yes');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
