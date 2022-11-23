-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 23-11-2022 a las 19:01:08
-- Versión del servidor: 10.4.25-MariaDB
-- Versión de PHP: 8.1.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `proyecto 502`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cursos`
--

CREATE TABLE `cursos` (
  `ID` int(2) NOT NULL,
  `NOMBRE` varchar(100) NOT NULL,
  `CARACTERÍSTICAS` longtext NOT NULL,
  `ID_COORDINADOR` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `cursos`
--

INSERT INTO `cursos` (`ID`, `NOMBRE`, `CARACTERÍSTICAS`, `ID_COORDINADOR`) VALUES
(1, 'C-1', 'Esta es la información del curso 1', 1),
(2, 'C-2', 'Esta es la información del curso 2', 2),
(3, 'C-3', 'Esta es la información del curso 3', 3),
(4, 'C-4', 'Esta es la información del curso 4', 4),
(5, 'C-5', 'Esta es la información del curso 5', 5),
(6, 'C-6', 'Esta es la información del curso 6', 6);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `roles`
--

CREATE TABLE `roles` (
  `TIPO` varchar(50) NOT NULL,
  `ID_ROL` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `roles`
--

INSERT INTO `roles` (`TIPO`, `ID_ROL`) VALUES
('Administrador', 1),
('Participante', 2),
('Coord.Cur', 3),
('Visitante', 4),
('Coord.Rec', 5);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `NOMBRE` varchar(50) NOT NULL,
  `EMAIL` varchar(30) NOT NULL,
  `ID_USUARIO` int(2) NOT NULL,
  `ID_ROL` int(2) NOT NULL,
  `ID_CURSO` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`NOMBRE`, `EMAIL`, `ID_USUARIO`, `ID_ROL`, `ID_CURSO`) VALUES
('Rafa Ruiz Moure', 'rarumo@gmail.com', 1, 1, 0),
('Pablo Torres Olmo', 'patool@gmail.com', 2, 2, 4);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `cursos`
--
ALTER TABLE `cursos`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `roles`
--
ALTER TABLE `roles`
  ADD PRIMARY KEY (`ID_ROL`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`ID_USUARIO`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
