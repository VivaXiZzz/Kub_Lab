def validate_in_list(allowed_values):
    def decorator(func):
        def wrapper(self, value):
            if value not in allowed_values:
                raise ValueError(f"Недопустимое значение: {value} \n Разрешенные значения: {allowed_values}")
            return func(self, value)

        return wrapper

    return decorator


tunes = ['Ces', 'Dur', 'as', 'moll', 'Ges', 'es', 'Des', 'b', 'As', 'f', 'Es', 'c', 'B', 'g', 'F', 'd', 'C', 'a', 'G',
         'e', 'D', 'h', 'A', 'fis', 'E', 'cis', 'H', 'gis', 'Fis', 'dis', 'Cis',
         'ais']

material = ['Дерево', 'Медь', 'Алюминий', 'Нитки']


class MusicalInstrument:
    def __init__(self, name: str, manufacturer: str, tone: str):
        self.name = name
        self.manufacturer = manufacturer
        self.tone = tone

    @property
    def tone(self):
        return self._tone

    @tone.setter
    @validate_in_list(tunes)
    def tone(self, value):
        self._tone = value

    def play_sound(self):
        raise NotImplemented("Должно быть определенно в классах наследниках")

    @staticmethod
    def tune():
        print("Инструмент настраивается")

    def __str__(self):
        return f"{self.name} \n Производитель: {self.manufacturer} \n Тональность: {self.tone}"


class Guitar(MusicalInstrument):
    def __init__(self, name: str, manufacturer: str, tone: str, string_count: int):
        super().__init__(name, manufacturer, tone)
        self.string_count = string_count

    @property
    def string_count(self):
        return self._string_count

    @string_count.setter
    def string_count(self, value):
        if value <= 0:
            raise ValueError("Количество струн должно быть положительным")
        self._string_count = value

    def play_sound(self):
        print("Звук крутой гитары")

    def __str__(self):
        return f"{super().__str__()} \n Кол-во струн: {self.string_count}"


class Piano(MusicalInstrument):
    def __init__(self, name: str, manufacturer: str, tone: str, key_count: int):
        super().__init__(name, manufacturer, tone)
        self.key_count = key_count

    @property
    def key_count(self):
        return self._key_count

    @key_count.setter
    def key_count(self, value):
        if value <= 0:
            raise ValueError("Количество клавиш должно быть положительным")
        self._key_count = value

    def play_sound(self):
        print("Звук классного пианино")

    def __str__(self):
        return f"{super().__str__()} \n Кол-во клавиш: {self.key_count}"


class Violin(MusicalInstrument):
    def __init__(self, name: str, manufacturer: str, tone: str, string_material: str):
        super().__init__(name, manufacturer, tone)
        self.string_material = string_material

    def play_sound(self):
        print("Звук неправильной гитары")

    def __str__(self):
        return f"{super().__str__()} \n Материал струн: {self.string_material}"


guitar = Guitar("Гимтара", "Гитарнозавод", "E", 6)
print(guitar)
guitar.play_sound()
guitar.tune()

piano = Piano("Пиманино", "Пиманинозавод", "C", 7)
print(piano)
piano.play_sound()

violin = Violin("Скримпка", "Скримпказавод", "Esad", "Дерево")
print(violin)
violin.play_sound()
