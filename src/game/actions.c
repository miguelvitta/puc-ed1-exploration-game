#include "actions.h"

/*
Implement handling of player commands:
- Movement: validate, run pathfinding, update explorer
- Open chest: check adjacency, reveal content
- Use potion: apply effect to explorer
- Undo: restore previous state using UndoStack
*/
