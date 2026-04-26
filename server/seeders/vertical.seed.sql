INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Vertical, Stairs F5-F4 --- */
  SELECT 'ST-L1-DOWN-F4', 'ST-L1-UP-F5' UNION ALL
  SELECT 'ST-R1-DOWN-F4', 'ST-R1-UP-F5'
)
SELECT 1, 0, 1, 5.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;


INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Vertical, Elevator F5-F4 --- */
  SELECT 'EL-EDI-F5', 'EL-EDI-F4'
)
SELECT 1, 0, 1, 2.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
