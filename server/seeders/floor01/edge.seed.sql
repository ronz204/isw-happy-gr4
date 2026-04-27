INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Eje Horizontal, Centro --- */
  SELECT 'PING-PONG-F1', 'CHILL-F1' UNION ALL
  SELECT 'PING-PONG-F1', 'EL-EDI-F1' UNION ALL

  /* --- Eje Horizontal, Izquierda Edificio --- */
  SELECT 'PING-PONG-F1', 'WP-F1-39' UNION ALL
  SELECT 'WP-F1-39', 'WP-F1-40' UNION ALL
  SELECT 'WP-F1-40', 'WP-F1-41' UNION ALL

  SELECT 'WP-F1-41', 'R-306-F1' UNION ALL
  SELECT 'WP-F1-40', 'R-305-F1' UNION ALL
  SELECT 'WP-F1-39', 'R-304-F1' UNION ALL

  SELECT 'WP-F1-39', 'ST-L1-UP-F2' UNION ALL

  /* --- Eje Horizontal, Derecha Edificio --- */
  SELECT 'PING-PONG-F1', 'WP-F1-42' UNION ALL
  SELECT 'WP-F1-42', 'WP-F1-43' UNION ALL
  SELECT 'WP-F1-43', 'WP-F1-44' UNION ALL

  SELECT 'WP-F1-42', 'R-303-F1' UNION ALL
  SELECT 'WP-F1-43', 'R-302-F1' UNION ALL
  SELECT 'WP-F1-44', 'R-301-F1' UNION ALL

  SELECT 'WP-F1-44', 'ST-R1-UP-F2' UNION ALL

  /* --- Eje Horizontal, Biblioteca --- */
  SELECT 'LIBRARY-F1', 'EL-LIB-F1' UNION ALL
  SELECT 'LIBRARY-F1', 'ST-LIB-F1' UNION ALL
  SELECT 'LIBRARY-F1', 'BATH-F1-LIB'
)
SELECT 0, 1, 1, 10.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
