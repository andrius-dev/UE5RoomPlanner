#pragma once

#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "CoreMinimal.h"
#include "Data/InteriorItemSaveData.h"
#include "Data/InteriorSaveData.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "UObject/NoExportTypes.h"
#include "SaveFileManager.generated.h"

/**
 * Utility for saving and loading interior
 */
UCLASS()
class ROOMPLANNER01_API ASaveFileManager : public AActor {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SaveFile")
	bool SaveInteriorData(const FInteriorSaveData& SaveData);

	UFUNCTION(BlueprintCallable, Category = "SaveFile")
	FInteriorSaveData LoadInteriorData();

private:
	UFUNCTION()
	bool OpenFileDialog(
		const FString& DialogTitle,
		const FString& DefaultPath,
		const FString& FileTypes,
		TArray<FString>& OutFileNames
	);

	UFUNCTION()
	bool OpenSaveFileDialog(
		const FString& DialogTitle,
		const FString& DefaultPath,
		const FString& FileTypes,
		TArray<FString>& OutFileNames
	);
};
