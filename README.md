 # Курсовая работа LinkTamer

## ✍️ Описание
Проект представлен в виде сервиса для сокращения ссылок, развернутого на облачном хостинге. Ознакомиться с прототипом можно по ссылке http://linktamer.xyz

## 🛠 Технологии
В рамках работы было задействовано множество современных технологий. Среди них:
* [Oatpp](https://oatpp.io/) - C++ фреймворк для создания REST API со Swagger документацией и ORM
* [Svelte](https://ru.svelte.dev/) - JavaScript фреймворк-компилятор для создания интерактивных веб-приложений
* [Docker](https://www.docker.com/) - контейнеризация приложения для кросс-платформенности и упрощения запуска

## 📝 Техническое задание
1. Установить фреймворки
2. Изучить документацию
3. Создать backend приложения
4. Создать frontend приложения
5. Соединить обе части
6. Обернуть проект в Docker контейнеры

#### Описание ТЗ
Сервис должен позволять быстро сокращать ссылки и сохранять всю информацию в базе данных. На стороне frontend должно быть реализовано два окна. Первое позволит сокращать ссылки и будет отображать историю пользователя. Второе будет загружать полные ссылки и производить переход по ним. На стороне backend будет создано несколько endpoint API и документация к ним на Swagger UI. Вся информация будет сохраняться в базе данных Sqlite3.

## 🐳  Запуск через Docker
Для запуска необходимо иметь Docker и Docker Compose. Далее внутри папки проекта, где находится файл docker-compose.yml прописать в командной строке

```
$: docker-compose up --build
```

## 🦾 Запуск вручную
### Frontend
Установить [NodeJS](https://nodejs.org/en/), убедиться, что путь до npm указан в переменной среды Path.
В папке frontend выполнить команды:
```
$: npm install
$: npm run build
```
Результат компиляции будет лежать в папке _public/build_, для запуска используется _index.html_

### Backend
Установить зависимости С++, используя *utils/install-oatpp-modules.sh* или [*vcpkg*](https://vcpkg.readthedocs.io/en/latest/)
Необходимые модули:
- [oatpp](https://github.com/oatpp/oatpp)
- [oatpp-sqlite](https://github.com/oatpp/oatpp-sqlite)
- [oatpp-swagger](https://github.com/oatpp/oatpp-swagger)

#### Установка через скрипт
Запустить скрипт *utils/install-oatpp-modules.sh*, все нужные модули установятся и соберутся автоматически

#### Установка через vcpkg
Выполнить следующие команды в папке, где будет установлен vcpkg
```
$: git clone https://github.com/microsoft/vcpkg
$: vcpkg\bootstrap-vcpkg.bat
```
Установить нужные библиотеки
```
$: vcpkg install oatpp
$: vcpkg install oatpp-sqlite
$: vcpkg install oatpp-swagger
```
После установки необходимо включить интеграцию в сборку
```
$: vcpkg integrate install
```
В консоли отобразится подсказка. В дальнейшем нужно использовать переменную -DCMAKE_TOOLCHAIN_FILE с местом расположения установленных библиотек при сборке проекта. 

## 🎉 Результат
- Frontend: http://linktamer.xyz
- Backend:  http://linktamer.xyz:8000
- Swagger:  http://linktamer.xyz:8000/swagger/ui

## 📋 TODO
1. Добавить Traefik для поддержки https подключений
2. Оптимизировать backend контейнер
