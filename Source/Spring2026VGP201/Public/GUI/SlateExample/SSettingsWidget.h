// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/GameHUD.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SPRING2026VGP201_API SSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, GameHUD)
	SLATE_ARGUMENT(int, MyInt)
	SLATE_END_ARGS()

	TWeakObjectPtr<class AGameHUD> GameHUD;
	int MyInt;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnIntClicked() const;
	FReply OnQuitClicked() const;

	/*
	--------------------------------- Smart Poniters ---------------------------------

		Unique Pointers: UniquePtr<T> = UniquePtr<int> score
			- Sole Owner of the objectt it points to
			- Cannot be copied, only moved
			- Automatically deletes the object when it goes out of scope
			- Eg. ScoreManager
	
		Shared Pointers: SharedPtr<T> = SharedPtr<int> PlayerHealth
			- Multiple ownership of the object it points to
			- Can be copied and shared among multiple SharedPtr instances
			- Automatically deletes the object when the last SharedPtr goes out of scope
			- Eg. UI Widgets, game objects shared across different systems (e.g., a character's health that both the character and the UI need to access)

		Weak Pointers: WeakPtr<T> = WeakPtr<int> EnemyTarget
			- Non-owning reference to an object managed by a SharedPtr
			- Doesn't affect reference count
			- Can be used to break circular references
			- Must be converted to SharedPtr before accessing the object
			- Eg. Observers, caches

		Soft Object Pointers: SoftObjectPtr<T> = SoftObjectPtr<UStaticMesh> HugeCity
			- Reference to an object that may not be loaded in memory
			- Load assets on demand
			-  Eg. Useful for large assets or assets that are not always needed, such as a huge city mesh that is only loaded when the player enters the city area
	*/
};
