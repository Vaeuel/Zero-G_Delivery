// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeroGDelivery/Public/Player/DroneCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDroneCharacter() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_ZeroGDelivery();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_ADroneCharacter();
ZEROGDELIVERY_API UClass* Z_Construct_UClass_ADroneCharacter_NoRegister();
// End Cross Module References

// Begin Class ADroneCharacter
void ADroneCharacter::StaticRegisterNativesADroneCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADroneCharacter);
UClass* Z_Construct_UClass_ADroneCharacter_NoRegister()
{
	return ADroneCharacter::StaticClass();
}
struct Z_Construct_UClass_ADroneCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/DroneCharacter.h" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DroneMesh_MetaData[] = {
		{ "Category", "DroneCharacter" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Called to bind functionality to input\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to bind functionality to input" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "DroneCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "DroneCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrustStrength_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YawThrustStrength_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YawResponseSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CenterOfMassOffset_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelingTorque_MetaData[] = {
		{ "Category", "Stabilization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Stores Center of mass offset in local space\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/DroneCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stores Center of mass offset in local space" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DroneMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrustStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_YawThrustStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_YawResponseSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CenterOfMassOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LevelingTorque;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADroneCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_DroneMesh = { "DroneMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, DroneMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DroneMesh_MetaData), NewProp_DroneMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrustStrength = { "ThrustStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, ThrustStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrustStrength_MetaData), NewProp_ThrustStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_YawThrustStrength = { "YawThrustStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, YawThrustStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YawThrustStrength_MetaData), NewProp_YawThrustStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_YawResponseSpeed = { "YawResponseSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, YawResponseSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YawResponseSpeed_MetaData), NewProp_YawResponseSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_CenterOfMassOffset = { "CenterOfMassOffset", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, CenterOfMassOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CenterOfMassOffset_MetaData), NewProp_CenterOfMassOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_LevelingTorque = { "LevelingTorque", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADroneCharacter, LevelingTorque), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelingTorque_MetaData), NewProp_LevelingTorque_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADroneCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_DroneMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrustStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_YawThrustStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_YawResponseSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_CenterOfMassOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_LevelingTorque,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADroneCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeroGDelivery,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADroneCharacter_Statics::ClassParams = {
	&ADroneCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADroneCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ADroneCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADroneCharacter()
{
	if (!Z_Registration_Info_UClass_ADroneCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADroneCharacter.OuterSingleton, Z_Construct_UClass_ADroneCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADroneCharacter.OuterSingleton;
}
template<> ZEROGDELIVERY_API UClass* StaticClass<ADroneCharacter>()
{
	return ADroneCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADroneCharacter);
ADroneCharacter::~ADroneCharacter() {}
// End Class ADroneCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADroneCharacter, ADroneCharacter::StaticClass, TEXT("ADroneCharacter"), &Z_Registration_Info_UClass_ADroneCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADroneCharacter), 1257416213U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_248517272(TEXT("/Script/ZeroGDelivery"),
	Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZeroGDelivery_Source_ZeroGDelivery_Public_Player_DroneCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
