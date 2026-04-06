from elements_state import ElementsState
data_brendan3_elements = ElementsState(
    CC = 5,
    ELEMENTS_TOP = [
        0b00010,0b00010,0b00100,
        0b00100,0b01000,0b10000,
        0b01000,0b10000,0b01000],
    ELEMENTS_RIGHT = [
        0b00010,0b00100,0b00010,
        0b00100,0b00100,0b00010,
        0b00010,0b00100,0b01000],
    ELEMENTS_BOTTOM = [
        0b00001,0b00001,0b00001,
        0b00001,0b00001,0b00001,
        0b00001,0b00001,0b10000],
    ELEMENTS_LEFT = [
        0b00001,0b00001,0b00001,
        0b00001,0b00010,0b00010,
        0b00100,0b00100,0b10000],
)