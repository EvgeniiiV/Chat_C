За основу проекта взята возможность общения в группах любого состава из числа зарегистрированных участников. При этом номера групп создаются автоматически, и для отправки сообщения нужно просто выбрать номер группы из списка. Группа может состоять минимум из 2- пользователей, что соответствует персональному чату, а максимальное количество участников в группе лимитировано числом зарегистрированных пользователей. Отправка сообщения в последнем случае так же является способом отправки сообщения всем пользователям.

Этап – регистрация. Выполняется сразу минимум для двух пользователей. Требует выбора оригинальных имен, а также оригинального значения конкатенации строк login + password.
Авторизация. Проверка на наличие данного пользователя в числе зарегистрированных. Предлагается выбрать действие, либо выбор контакта из числа тех, с которыми уже велась переписка (п. 4), при этом проверяется наличие предыдущих контактов, либо создать контакт для начала переписки (п.3).
Создание контакта – просто выбор одного или нескольких контактов из числа зарегистрированных (данный список доступен после регистрации очередного пользователя) для отправки сообщения. Здесь проверяем:
Наличие точно такой группы среди уже созданных. В этом случае предлагается перейти к выбору данной группы для продолжения общения. Для унификации группы используется сортировка имен по возрастанию и поэлементное сравнение с уже имеющимися контактами (группами).
Возможность добавить пользователя, если все пользователи уже в этой группе
Внесение авторизованного в данный момент пользователя в группу происходит автоматически и запрещено программой, так же как повторное внесение пользователя в группу.
Наличие выбранного пользователя среди зарегистрированных. После внесения очередного пользователя в группу состав группы выводится в консоль.
При возврате в п.3 проверяется возможность создания оригинального сочетания контактов, т.е. группы уникальной по своему составу. Количество потенциальных оригинальных сочетаний определяется формулой, основанной на базовой для сочетаний: Ckn = n!/((n−k)!⋅k!) (https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%87%D0%B5%D1%82%D0%B0%D0%BD%D0%B8%D0%B5) , которая имеет вид Сkn = (n-1)!/((n-(n-1))!(n-1)! + (n-1)!/((n-(n-2))!(n-2)! + (n-1)!/((n-(n-3))!*(n-3)! .... + n, до n - a = 2, где n- количество зарегистрированных пользователей, k - количество участников в группе, 2-минимальное количество пользолвателей в одной группе.
Предлагает общение с ранее выбранными пользователями (п.5) или отправить сообщение во все имеющиеся на текущий момент группы (п.6).
Предлагает написать и отправить сообщение выбранному контакту. Предлагается возможность перехода к любому из описанных здесь пунктов (от регистрации, п. 1 до отправки сообщения всем пользователям, п.6) или выход из программы
Предлагает написать и отправить сообщение всем имеющимся контактам. В данном случае сообщение получат только уже созданные контакты (группы), т.е. те пользователи, которые проходили авторизацию и писали сообщения, а так же те, кому они писали, т.е. те пользователи, которые приняли участие в переписке, либо как отправители, либо как получатели. Если же это не так, то для отправки сообщения всем пользователям нужно создать общий чат в п.3, внеся всех пользователей в одну группу. Далее предлагается возможность перехода к любому из описанных здесь пунктов (от регистрации, п. 1 до отправки сообщения всем пользователям, п.6) или выход из программы.