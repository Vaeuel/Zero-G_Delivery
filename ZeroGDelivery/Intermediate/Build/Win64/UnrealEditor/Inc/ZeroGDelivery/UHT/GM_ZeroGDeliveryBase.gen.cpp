// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeroGDelivery/Public/GM_ZeroGDeliveryBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGM_ZeroGDeliveryBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_ZeroGDelivery();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_AGM_ZeroGDeliveryBase();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_AGM_ZeroGDeliveryBase_NoRegister();
// End Cross Module References

// Begin Class AGM_ZeroGDeliveryBase
void AGM_ZeroGDeliveryBase::StaticRegisterNativesAGM_ZeroGDeliveryBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGM_ZeroGDeliveryBase);
UClass* Z_Construct_UClass_AGM_ZeroGDeliveryBase_NoRegister()
{
	return AGM_ZeroGDeliveryBase::StaticClass();
}
struct Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GM_ZeroGDeliveryBase.h" },
		{ "ModuleRelativePath", "Public/GM_ZeroGDeliveryBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGM_ZeroGDeliveryBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeroGDelivery,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics::ClassParams = {
	&AGM_ZeroGDeliveryBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGM_ZeroGDeliveryBase()
{
	if (!Z_Registration_Info_UClass_AGM_ZeroGDeliveryBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGM_ZeroGDeliveryBase.OuterSingleton, Z_Construct_UClass_AGM_ZeroGDeliveryBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGM_ZeroGDeliveryBase.OuterSingleton;
}
template<> ZEROGDELIVERY_API UClass* StaticClass<AGM_ZeroGDeliveryBase>()
{
	return AGM_ZeroGDeliveryBase::StaticClass();
}
AGM_ZeroGDeliveryBase::AGM_ZeroGDeliveryBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGM_ZeroGDeliveryBase);
AGM_ZeroGDeliveryBase::~AGM_ZeroGDeliveryBase() {}
// End Class AGM_ZeroGDeliveryBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGM_ZeroGDeliveryBase, AGM_ZeroGDeliveryBase::StaticClass, TEXT("AGM_ZeroGDeliveryBase"), &Z_Registration_Info_UClass_AGM_ZeroGDeliveryBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGM_ZeroGDeliveryBase), 1815241303U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_3931673110(TEXT("/Script/ZeroGDelivery"),
	Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_GM_ZeroGDeliveryBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
