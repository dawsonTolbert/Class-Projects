-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Dec 02, 2022 at 02:18 AM
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
-- Database: `games`
--

-- --------------------------------------------------------

--
-- Table structure for table `pc`
--

CREATE TABLE `pc` (
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pc`
--

INSERT INTO `pc` (`name`, `genre`, `console`, `release year`, `rating`) VALUES
('Counter Strike: Global Offensive', 'Tactical First-person Shooter', 'PC', 2012, '8'),
('Portal 2', 'Puzzle-platform', 'PC', 2011, '10'),
('Minecraft', 'Sandbox', 'PC', 2011, '9'),
('Valorant', 'Tactical First-person Hero Shooter', 'PC', 2020, '9'),
('Overwatch 2', 'First-person Hero Shooter', 'PC', 2022, '8');

-- --------------------------------------------------------

--
-- Table structure for table `playstation`
--

CREATE TABLE `playstation` (
  `name` varchar(128) COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `playstation`
--

INSERT INTO `playstation` (`name`, `genre`, `console`, `release year`, `rating`) VALUES
('God of War Ragnarok', 'Action-adventure', 'PS4/PS5', 2022, '10'),
('Uncharted 4: A Thief\'s End', 'Action-adventure', 'PS4/PS5', 2016, '9'),
('Elden Ring', 'Action RPG', 'PS4/PS5', 2022, '10'),
('DOOM Eternal', 'First-person Shooter', 'PS4/PS5', 2020, '9'),
('Grand Theft Auto V', 'Open-world Action', 'PS3/PS4/PS5', 2013, '10');

-- --------------------------------------------------------

--
-- Table structure for table `switch`
--

CREATE TABLE `switch` (
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `switch`
--

INSERT INTO `switch` (`name`, `genre`, `console`, `release year`, `rating`) VALUES
('Super Mario Odyssey', 'Platforming', 'Nintendo Switch', 2017, '10'),
('The Legend of Zelda: Breath of the Wild', 'Open-world Action-adventure', 'Nintendo Switch', 2017, '10'),
('Animal Crossing: New Horizons', 'Sim', 'Nintendo Switch', 2020, '8'),
('Mario Kart 8 Deluxe', 'Racing', 'Nintendo Switch', 2017, '9'),
('Super Smash Bros. Ultimate', 'Fighting', 'Nintendo Switch', 2018, '9');

-- --------------------------------------------------------

--
-- Table structure for table `xbox`
--

CREATE TABLE `xbox` (
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `genre` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `console` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `release year` int NOT NULL,
  `rating` decimal(10,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `xbox`
--

INSERT INTO `xbox` (`name`, `genre`, `console`, `release year`, `rating`) VALUES
('Halo Infinite', 'First-person Shooter', 'Series X/Series S/One', 2021, '9'),
('Forza Horizon 5', 'Racing', 'Series X/Series S/One', 2021, '10'),
('Gears 5', 'Third-person Shooter', 'Series X/Series S/One', 2019, '8'),
('Assassin\'s Creed Valhalla', 'Action RPG', 'Series X/Series S/One', 2018, '8'),
('Hitman 3', 'Stealth', 'Series X/Series S/One', 2021, '9');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
