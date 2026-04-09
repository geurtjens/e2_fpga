from grid_state import GridState

data_first_assignment_brendan3 = GridState(
    N = 3, # puzzle size
    V = 9, # number of variables in the grid
    CC = 5, ## colour count
    UNASSIGNED_VARIABLES = 0b111111110, # variables yet to be allocated a variable
    UNASSIGNED_TILES = 0b111111110, # tiles yet to be forced into a single position
    R0 = [
        0b000000000, 0b000000000, 0b000000000, 
        0b000000000, 0b100000000, 0b000000000, 
        0b000001110, 0b011110000, 0b000000000],
    R1 = [
        0b000000001, 0b000000000, 0b000000000, 
        0b011110000, 0b100000000, 0b000000000, 
        0b000000000, 0b000000000, 0b000000000],
    R2 = [
        0b000000000, 0b011110000, 0b000001110, 
        0b000000000, 0b100000000, 0b000000000, 
        0b000000000, 0b000000000, 0b000000000],
    R3 = [
        0b000000000, 0b000000000, 0b000000000, 
        0b000000000, 0b100000000, 0b011110000, 
        0b000000000, 0b000000000, 0b000001110],
    TOP = [
        0b00001, 0b00001, 0b00001, 
        0b00010, 0b11000, 0b00110, 
        0b00110, 0b11000, 0b00110],
    RIGHT = [
        0b00010, 0b00110, 0b00001, 
        0b11000, 0b11000, 0b00001, 
        0b00110, 0b00110, 0b00001],
    BOTTOM = [
        0b00010, 0b11000, 0b00110, 
        0b00110, 0b11000, 0b00110, 
        0b00001, 0b00001, 0b00001],
    LEFT = [
        0b00001, 0b00010, 0b00110, 
        0b00001, 0b11000, 0b11000, 
        0b00001, 0b00110, 0b00110],
    VARIABLE_TO_ASSIGN = 0, # variableId for next assignment expected
    TILE_TO_ASSIGN = 0, # tileId for next assignment expected,
    ROTATION_TO_ASSIGN = 1, # rotation for next assignment expected
    DEADEND = False, # deadend expected
    UPDATED = False # update expected
)
