# Game_of_Life_Qt

Место действия — это размеченная на клетки замкнутая поверхность(верхняя граница поля «соединена» с нижней, а левая граница — с правой,) Пользователь задает размер поля и расставляет начальное положение «живых» клеток, которые затем взаимодействуют согласно правилам:

  1)В пустой (мёртвой) клетке, рядом с которой ровно три живые клетки, зарождается жизнь;
2) Если у живой клетки есть две или три живые соседки, то эта клетка продолжает жить; в противном случае, если соседей меньше двух или больше трёх, клетка умирает («от одиночества» или «от перенаселённости»)

Игра прекращается, если:

1)На поле не останется ни одной «живой» клетки(Игрок проиграл)
2)конфигурация на очередном шаге в точности (без сдвигов и поворотов) повторит себя же на одном из более ранних шагов (складывается периодическая конфигурация) при очередном шаге ни одна из клеток не меняет своего состояния (складывается стабильная конфигурация; предыдущее правило, вырожденное до одного шага назад)(Игрок победил)
Примерный алгоритм:

Одна клетка - структура с координатми(x,y). Создается неупорядоченное словарь. состоящий из структур и прямоугольников.Поиск соcедей будет происходить с помощью find.После их подсчета, изменения будут отображены на экране. Перед изменением словаря, будет произведена проверка, чтобы сравнить изменения. Если их нет и есть живые клетки, то игрок победил. Если нет изменений и нет живых клеток, то проиграл.
