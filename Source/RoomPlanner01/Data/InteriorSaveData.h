#pragma once
#include "InteriorItemSaveData.h"
#include "InteriorSaveData.generated.h"

USTRUCT(BlueprintType)
struct ROOMPLANNER01_API FInteriorSaveData {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FInteriorItemSaveData> InteriorItems;
};