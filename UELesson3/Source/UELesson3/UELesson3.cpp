// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELesson3.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, UELesson3, "UELesson3" );
 
// CameraСomponent та SpringArmComponent - в парі використовуються для надання перспективного зображення для pawn;
// AudioComponent - використовується для створення та маніпуляції звуковою компонентою всередині гри;
// ChildActorComponent - дозволяє використовувати актора іншого або того ж самого класу, як підоб’єкт. 
// WidgetComponent - дозволяє добавляти віджети до актора, взаємодіяти з ними та відображати як частину (наприклад рівень життя чи ім’я персонажа).
// SceneComponent - використовується як не візуальна компонента, для задання трансформу та правильної архітектури компонентів актора. До неї можна приєднувати інші компоненти.
// Shape Components (BoxComponent/CapsuleComponent/SphereComponent) - використовуються для обрахунку та створення колізій актору. Також використовуються як тригери до певних дій, наприклад наближення іншого актора.


// UCLASS()
//		Abstract - визначає абстрактний клас. Запобігає виставленню акторів цього класу на сцену. Не поширюється на дочірні класи;
//		BlueprintType  - визначає, що клас може бути використаний, як змінна у Blueprint скриптах;
//		Blueprintable - визначає, що клас прийнятний для створення Blueprint  нащадків;
//			Config=ConfigName - визначає, що цьому класу дозволено зберігати інформацію в конфігураційних файлах (.ini). ConfigName values are "Engine", "Editor", "Input", and "Game".
// USTRUCT()
//		BlueprintType - визначає, що структура може бути використана, як змінна у Blueprint скриптах;
// UFUNCTION()
//		BlueprintCallable - функція може бути викликана в  Blueprint;
//		BlueprintImplementableEvent - функція має бути імплементована в Blueprint;
//		BlueprintNativeEvent - функція, яка задумана для перевизначення у Blueprint, але повинна мати реалізацію у C++ (FunctionName_Implementation). Якщо при її виклику не буде знайдено реалізації в Blueprint, то викликається C++ реалізація.
//			Category = "TopCategory|SubCategory|Etc" - виносить функцію у відповідну категорію;
// Server - специфікація для мережевого коду, викликається лише на сервері;
// Client - специфікація для мережевого коду, викликається лише на клієнті;
//		NetMulticast - специфікація для мережевого коду, викликається локально на сервері та реплікується на всіх клієнтів
// UPROPERTY()
//		VisibleAnywhere - визначає, що властивість видима у всіх вікнах властивостей, але не дає можливості до редагування.
//		Несумісна зі специфікаторами класу “Edit”;
//		VisibleDefaultsOnly -  визначає, що властивість видима лише у вікнах властивостей Blueprint класах, але не об’єктів окремо, не дає можливості до редагування. Несумісна зі специфікаторами класу “Edit”;
//		EditAnywhere - визначає, що властивість може редагуватися у всіх вікнах властивостей;
//		EditDefaultsOnly - визначає, що властивість може редагуватися у вікнах властивостей Blueprint класах, але не об’єктів окремо;
//		Category = "TopCategory|SubCategory|Etc" - визначає категорію для властивості, під якою секцією категорій буде знаходитися інформація про неї;
//		BlueprintReadWrite - визначає права Blueprint класів до читання/запису цієї властивості;
//		BlueprintReadOnly - визначає права Blueprint класів до читання цієї властивості. Не має можливості змінити значення властивості через Blueprint;
//		Replicated - специфікація для мережевого коду, показує, що властивість повинна реплікуватися;
//		NotReplicated - специфікація для мережевого коду, ігнорує реплікацію;
// UENUM()
//		BlueprintType - визначає, що Enum може бути використаний, як змінна у Blueprint скриптах;