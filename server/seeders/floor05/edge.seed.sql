INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Eje Horizontal, Centro --- */
  SELECT 'BATH-F5', 'CHILL-F5' UNION ALL
  SELECT 'BATH-F5', 'EL-EDI-F5' UNION ALL

  /* --- Eje Horizontal, Izquierda Edificio --- */
  SELECT 'BATH-F5', 'WP-F5-21' UNION ALL
  SELECT 'WP-F5-21', 'WP-F5-22' UNION ALL
  SELECT 'WP-F5-22', 'WP-F5-23' UNION ALL

  SELECT 'WP-F5-23', 'R-324-F5' UNION ALL
  SELECT 'WP-F5-22', 'R-323-F5' UNION ALL
  SELECT 'WP-F5-21', 'R-322-F5' UNION ALL

  SELECT 'WP-F5-23', 'ST-L1-DOWN-F4' UNION ALL

  /* --- Eje Horizontal, Derecha Edificio --- */  
  SELECT 'BATH-F5', 'WP-F5-24' UNION ALL
  SELECT 'WP-F5-24', 'WP-F5-25' UNION ALL
  SELECT 'WP-F5-25', 'WP-F5-26' UNION ALL

  SELECT 'WP-F5-24', 'R-321-F5' UNION ALL
  SELECT 'WP-F5-25', 'R-320-F5' UNION ALL
  SELECT 'WP-F5-26', 'R-319-F5' UNION ALL

  SELECT 'WP-F5-26', 'ST-R1-DOWN-F4'
)
SELECT 0, 5, 1, 10.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
