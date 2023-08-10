// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELesson6.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, UELesson6, "UELesson6" );
 
 
/*
DELEGATES:
Single Delegate (Static Delegate) - найпростіший делегат, до якого можна прив’язати лише одного слухача.
DECLARE_DELEGATE(FSingleDelegate); - оголошення делегата;
FSingleDelegate OnSingleDelegate; - оголошення змінної делегата;
ASomeClass* SomeClass; - оголошення змінної класу-слухача;
OnSingleDelegate.BindRaw(SomeClass, &ASomeClass::SomeFunction); - прив’язка слухача;
OnSingleDelegate.ExecuteIfBound(); - виклик делегата.

Multicast Delegate - може прив’язувати більше, ніж одного слухача, проте вимагає більше часу та ресурсів.

DECLARE_MULTICAST_DELEGATE(FMulticastDelegate);  - оголошення делегата;
OnMulticastDelegate.AddRaw(SomeClass, &ASomeClass::SomeFunction); - прив’язка слухача;
OnMulticastDelegate.Broadcast(); - виклик делегата.

Dynamic Delegate - єдина різниця від Static Delegate - це можливість серіалізовуватися. І також вони повільніші.

DECLARE_DYNAMIC_DELEGATE(FDynamicDelegate); - оголошення делегата;
OnDynamicDelegate.BindDynamic(SomeClass, &ASomeClass::SomeFunction) - прив’язка слухача;
OnDynamicDelegate.ExecuteIfBound(); - виклик делегата.

Dynamic Multicast Delegate - найпотужніший делегат та водночас найповільніший.

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDynamicMulticastDelegate); - оголошення делегата;
OnDynamicMulticastDelegate.AddDynamic(SomeClass, &ASomeClass::SomeFunction); - прив’язка слухача;
OnDynamicMulticastDelegate.Broadcast(); - виклик делегата.

LEVELS:
UGameplayStatics::OpenLevel(GetWorld(), TEXT("LevelName"));

TIMERS:
FTimerHandle TimerHandle;
GetWorldTimerManager().SetTimer(TimerHandle, this, &ASomeClass::SomeFunction, 2.f, false);

*/