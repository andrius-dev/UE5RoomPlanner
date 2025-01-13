#pragma once
#include "InteriorItemSaveData.generated.h"


USTRUCT(BlueprintType)
struct ROOMPLANNER01_API FInteriorItemSaveData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MeshLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector WorldLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;
};
