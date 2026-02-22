// Ninja Bear Studio Inc., all rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NinjaCommonUIFunctionLibrary.generated.h"

class ANinjaCommonHUD;
class UCommonActionWidget;

/**
 * Set of helper functions for the Common UI layer.
 */
UCLASS()
class NINJACOMMONUI_API UNinjaCommonUIFunctionLibrary : public UBlueprintFunctionLibrary
{
	
	GENERATED_BODY()

public:

	/**
	 * Attempts to retrieve the HUD for a given actor (Pawn, Character, Controller).
	 */
	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category = "NBS|Common UI")
	static ANinjaCommonHUD* TryGetHUD(const AActor* Owner);

	/** 
	 * Progresses an Action Widget, with the provided hold percent amount.
	 * 
	 * Since the Common Action Widget does not expose its hold percent to blueprint,
	 * and subclassing it just for this would be too much, this function provides an
	 * easy and straightforward way to set the held percent from an external source.
	 * 
	 * A common example would be to have the held percent calculated somewhere, such
	 * as a ViewModel, or in a parent window. For those cases, this becomes handy.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "NBS|Common UI")
	static void ProgressActionWidget(UCommonActionWidget* ActionWidget, float HeldPercent);	
	
};
