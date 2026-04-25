# API Design — Happy GR4

Base URL: `http://localhost:4000`

---

## Enums de referencia

| Tipo | Valores válidos |
|---|---|
| **Profile** | `Regular`, `NewStudent`, `Wheelchair` |
| **Strategy** | `BFS`, `DFS`, `Dijkstra` |
| **NodeType** | `Waypoint`, `Room`, `Office`, `StairsUp`, `StairsDown`, `Elevator`, `Bathroom`, `Chilling`, `Entrance`, `Library`, `Cafeteria`, `Parking`, `Auditorium`, `Security` |
| **EdgeType** | `Walking`, `Stairs`, `Elevator` |
| **EdgeStatus** | `Open`, `Closed` |

---

## GET /health

Verifica que el servidor está corriendo.

**Request**
```
GET /health
```

**Response `200`**
```json
{
  "status": "Healthy",
  "service": "Happy GR4"
}
```

---

## GET /api/graph/landmarks

Retorna todos los nodos marcados como landmark.

**Request**
```
GET /api/graph/landmarks
```

**Response `200`**
```json
{
  "landmarks": [
    {
      "id": 1,
      "type": "Entrance",
      "floor": 4,
      "px": 120.5,
      "py": 340.0,
      "code": "ENT-04-01",
      "label": "Entrada principal piso 4",
      "isLandmark": true
    },
    {
      "id": 8,
      "type": "Library",
      "floor": 5,
      "px": 200.0,
      "py": 150.0,
      "code": "LIB-05-01",
      "label": "Biblioteca",
      "isLandmark": true
    }
  ]
}
```

---

## GET /api/graph/floor/:floor

Retorna todos los nodos y aristas pertenecientes a un piso específico.

**Request**
```
GET /api/graph/floor/4
```

| Parámetro de ruta | Tipo | Descripción |
|---|---|---|
| `floor` | `string` (número) | Número de piso |

**Response `200`**
```json
{
  "nodes": [
    {
      "id": 1,
      "type": "Waypoint",
      "floor": 4,
      "px": 100.0,
      "py": 200.0,
      "code": "WP-04-01",
      "label": "",
      "isLandmark": false
    },
    {
      "id": 2,
      "type": "Room",
      "floor": 4,
      "px": 150.0,
      "py": 200.0,
      "code": "ROOM-04-101",
      "label": "Salón 101",
      "isLandmark": false
    }
  ],
  "edges": [
    {
      "id": 10,
      "type": "Walking",
      "floor": 4,
      "status": "Open",
      "weight": 12.5,
      "fromNodeId": 1,
      "toNodeId": 2
    }
  ]
}
```

**Response `400` — piso inválido**
```json
{ "error": "Invalid floor number" }
```

---

## GET /api/graph/full

Retorna el grafo completo con todos los nodos y aristas de todos los pisos.

**Request**
```
GET /api/graph/full
```

**Response `200`**
```json
{
  "nodes": [
    {
      "id": 1,
      "type": "Waypoint",
      "floor": 4,
      "px": 100.0,
      "py": 200.0,
      "code": "WP-04-01",
      "label": "",
      "isLandmark": false
    }
  ],
  "edges": [
    {
      "id": 10,
      "type": "Walking",
      "floor": 4,
      "status": "Open",
      "weight": 12.5,
      "fromNodeId": 1,
      "toNodeId": 2
    },
    {
      "id": 11,
      "type": "Stairs",
      "floor": 4,
      "status": "Open",
      "weight": 20.0,
      "fromNodeId": 5,
      "toNodeId": 50
    }
  ]
}
```

---

## POST /api/graph/route

Busca la ruta entre dos nodos usando el algoritmo y perfil indicados. Retorna el camino completo con coordenadas de cada nodo.

**Request**
```
POST /api/graph/route
Content-Type: application/json
```

```json
{
  "startNodeId": 1,
  "endNodeId": 42,
  "profile": "Regular",
  "strategy": "Dijkstra"
}
```

| Campo | Tipo | Requerido | Descripción |
|---|---|---|---|
| `startNodeId` | `number` | ✅ | ID del nodo de origen |
| `endNodeId` | `number` | ✅ | ID del nodo de destino |
| `profile` | `string` | ✅ | Perfil del usuario |
| `strategy` | `string` | ✅ | Algoritmo de búsqueda |

**Response `200` — ruta encontrada**
```json
{
  "success": true,
  "algorithm": "Dijkstra",
  "distance": 87.4,
  "time": 0.35,
  "path": [
    { "code": "WP-04-01", "px": 100.0, "py": 200.0, "type": "Waypoint" },
    { "code": "WP-04-05", "px": 130.0, "py": 200.0, "type": "Waypoint" },
    { "code": "ROOM-04-205", "px": 160.0, "py": 200.0, "type": "Room" }
  ]
}
```

**Response `200` — sin ruta**
```json
{
  "success": false,
  "algorithm": "Dijkstra",
  "distance": 0,
  "time": 0.12,
  "path": [],
  "message": "No path found between the specified nodes"
}
```

**Response `400` — validación**
```json
{ "error": "Invalid strategy. Valid values: BFS, DFS, Dijkstra" }
```

---

## POST /api/graph/performance

Ejecuta los 3 algoritmos (BFS, DFS, Dijkstra) sobre el mismo grafo y perfil, y retorna un resumen comparativo de distancia y tiempo. **No incluye la lista de nodos del camino.**

**Request**
```
POST /api/graph/performance
Content-Type: application/json
```

```json
{
  "startNodeId": 1,
  "endNodeId": 42,
  "profile": "Wheelchair"
}
```

| Campo | Tipo | Requerido | Descripción |
|---|---|---|---|
| `startNodeId` | `number` | ✅ | ID del nodo de origen |
| `endNodeId` | `number` | ✅ | ID del nodo de destino |
| `profile` | `string` | ✅ | Perfil del usuario |

**Response `200`**
```json
{
  "results": [
    { "algorithm": "BFS",      "success": true, "distance": 102.0, "time": 0.18 },
    { "algorithm": "DFS",      "success": true, "distance": 145.5, "time": 0.09 },
    { "algorithm": "Dijkstra", "success": true, "distance": 87.4,  "time": 0.35 }
  ]
}
```

**Response `400` — validación**
```json
{ "error": "Invalid profile type. Valid values: Regular, NewStudent, Wheelchair" }
```

---

## PATCH /api/edge/:id/close

Cierra una arista, impidiendo que cualquier perfil la use en la navegación.

**Request**
```
PATCH /api/edge/10/close
```

| Parámetro de ruta | Tipo | Descripción |
|---|---|---|
| `id` | `string` (número) | ID de la arista |

**Response `200`**
```json
{
  "id": 10,
  "type": "Walking",
  "floor": 4,
  "status": "Closed",
  "weight": 12.5,
  "fromNodeId": 1,
  "toNodeId": 2,
  "message": "Edge closed successfully"
}
```

**Response `404`**
```json
{ "error": "Edge not found" }
```

---

## PATCH /api/edge/:id/open

Abre una arista previamente cerrada, habilitándola de nuevo para la navegación.

**Request**
```
PATCH /api/edge/10/open
```

| Parámetro de ruta | Tipo | Descripción |
|---|---|---|
| `id` | `string` (número) | ID de la arista |

**Response `200`**
```json
{
  "id": 10,
  "type": "Walking",
  "floor": 4,
  "status": "Open",
  "weight": 12.5,
  "fromNodeId": 1,
  "toNodeId": 2,
  "message": "Edge opened successfully"
}
```

**Response `404`**
```json
{ "error": "Edge not found" }
```

---

## Resumen de endpoints

| Método | Ruta | Descripción |
|---|---|---|
| `GET` | `/health` | Health check |
| `GET` | `/api/graph/landmarks` | Nodos landmark |
| `GET` | `/api/graph/floor/:floor` | Nodos y aristas por piso |
| `GET` | `/api/graph/full` | Grafo completo |
| `POST` | `/api/graph/route` | Ruta con algoritmo específico |
| `POST` | `/api/graph/performance` | Comparativa de los 3 algoritmos |
| `PATCH` | `/api/edge/:id/close` | Cerrar arista |
| `PATCH` | `/api/edge/:id/open` | Abrir arista |
