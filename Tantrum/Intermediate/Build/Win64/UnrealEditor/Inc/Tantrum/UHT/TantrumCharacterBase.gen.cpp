// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tantrum/TantrumCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTantrumCharacterBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumCharacterBase();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumCharacterBase_NoRegister();
	TANTRUM_API UClass* Z_Construct_UClass_AThrowableActor_NoRegister();
	TANTRUM_API UClass* Z_Construct_UClass_UInteractInterface_NoRegister();
	TANTRUM_API UEnum* Z_Construct_UEnum_Tantrum_ECharacterThrowState();
	UPackage* Z_Construct_UPackage__Script_Tantrum();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECharacterThrowState;
	static UEnum* ECharacterThrowState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECharacterThrowState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECharacterThrowState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Tantrum_ECharacterThrowState, (UObject*)Z_Construct_UPackage__Script_Tantrum(), TEXT("ECharacterThrowState"));
		}
		return Z_Registration_Info_UEnum_ECharacterThrowState.OuterSingleton;
	}
	template<> TANTRUM_API UEnum* StaticEnum<ECharacterThrowState>()
	{
		return ECharacterThrowState_StaticEnum();
	}
	struct Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::Enumerators[] = {
		{ "ECharacterThrowState::None", (int64)ECharacterThrowState::None },
		{ "ECharacterThrowState::RequestingPull", (int64)ECharacterThrowState::RequestingPull },
		{ "ECharacterThrowState::Pulling", (int64)ECharacterThrowState::Pulling },
		{ "ECharacterThrowState::Attached", (int64)ECharacterThrowState::Attached },
		{ "ECharacterThrowState::Throwing", (int64)ECharacterThrowState::Throwing },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::Enum_MetaDataParams[] = {
		{ "Attached.DisplayName", "Attached" },
		{ "Attached.Name", "ECharacterThrowState::Attached" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ECharacterThrowState::None" },
		{ "Pulling.DisplayName", "Pulling" },
		{ "Pulling.Name", "ECharacterThrowState::Pulling" },
		{ "RequestingPull.DisplayName", "RequestingPull" },
		{ "RequestingPull.Name", "ECharacterThrowState::RequestingPull" },
		{ "Throwing.DisplayName", "Throwing" },
		{ "Throwing.Name", "ECharacterThrowState::Throwing" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Tantrum,
		nullptr,
		"ECharacterThrowState",
		"ECharacterThrowState",
		Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Tantrum_ECharacterThrowState()
	{
		if (!Z_Registration_Info_UEnum_ECharacterThrowState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECharacterThrowState.InnerSingleton, Z_Construct_UEnum_Tantrum_ECharacterThrowState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECharacterThrowState.InnerSingleton;
	}
	DEFINE_FUNCTION(ATantrumCharacterBase::execIsThrowingObject)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsThrowingObject();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATantrumCharacterBase::execIsPullingObject)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPullingObject();
		P_NATIVE_END;
	}
	void ATantrumCharacterBase::StaticRegisterNativesATantrumCharacterBase()
	{
		UClass* Class = ATantrumCharacterBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsPullingObject", &ATantrumCharacterBase::execIsPullingObject },
			{ "IsThrowingObject", &ATantrumCharacterBase::execIsThrowingObject },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics
	{
		struct TantrumCharacterBase_eventIsPullingObject_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TantrumCharacterBase_eventIsPullingObject_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TantrumCharacterBase_eventIsPullingObject_Parms), &Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATantrumCharacterBase, nullptr, "IsPullingObject", nullptr, nullptr, Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::TantrumCharacterBase_eventIsPullingObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::TantrumCharacterBase_eventIsPullingObject_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics
	{
		struct TantrumCharacterBase_eventIsThrowingObject_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TantrumCharacterBase_eventIsThrowingObject_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TantrumCharacterBase_eventIsThrowingObject_Parms), &Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATantrumCharacterBase, nullptr, "IsThrowingObject", nullptr, nullptr, Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::TantrumCharacterBase_eventIsThrowingObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::TantrumCharacterBase_eventIsThrowingObject_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATantrumCharacterBase);
	UClass* Z_Construct_UClass_ATantrumCharacterBase_NoRegister()
	{
		return ATantrumCharacterBase::StaticClass();
	}
	struct Z_Construct_UClass_ATantrumCharacterBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinImpactSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinImpactSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxImpactSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxImpactSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinStunTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinStunTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxStunTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStunTime;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CharacterThrowState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterThrowState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CharacterThrowState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrowSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrowSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrowMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrowMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrowableActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrowableActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATantrumCharacterBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Tantrum,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ATantrumCharacterBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATantrumCharacterBase_IsPullingObject, "IsPullingObject" }, // 3954489490
		{ &Z_Construct_UFunction_ATantrumCharacterBase_IsThrowingObject, "IsThrowingObject" }, // 3878922007
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TantrumCharacterBase.h" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_SprintSpeed_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_SprintSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinImpactSpeed_MetaData[] = {
		{ "Category", "Fall Impact" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinImpactSpeed = { "MinImpactSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, MinImpactSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinImpactSpeed_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinImpactSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxImpactSpeed_MetaData[] = {
		{ "Category", "Fall Impact" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxImpactSpeed = { "MaxImpactSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, MaxImpactSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxImpactSpeed_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxImpactSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinStunTime_MetaData[] = {
		{ "Category", "Fall Impact" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Time in Seconds\n" },
#endif
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time in Seconds" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinStunTime = { "MinStunTime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, MinStunTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinStunTime_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinStunTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxStunTime_MetaData[] = {
		{ "Category", "Fall Impact" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxStunTime = { "MaxStunTime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, MaxStunTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxStunTime_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxStunTime_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState_MetaData[] = {
		{ "Category", "Throw" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState = { "CharacterThrowState", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, CharacterThrowState), Z_Construct_UEnum_Tantrum_ECharacterThrowState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState_MetaData) }; // 260039719
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowSpeed_MetaData[] = {
		{ "Category", "Throw" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
		{ "Unit", "ms" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowSpeed = { "ThrowSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, ThrowSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowSpeed_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowMontage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowMontage = { "ThrowMontage", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, ThrowMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowMontage_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowableActor_MetaData[] = {
		{ "ModuleRelativePath", "TantrumCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowableActor = { "ThrowableActor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumCharacterBase, ThrowableActor), Z_Construct_UClass_AThrowableActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowableActor_MetaData), Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowableActor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATantrumCharacterBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_SprintSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinImpactSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxImpactSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MinStunTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_MaxStunTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_CharacterThrowState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumCharacterBase_Statics::NewProp_ThrowableActor,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ATantrumCharacterBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractInterface_NoRegister, (int32)VTABLE_OFFSET(ATantrumCharacterBase, IInteractInterface), false },  // 405113120
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATantrumCharacterBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATantrumCharacterBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATantrumCharacterBase_Statics::ClassParams = {
		&ATantrumCharacterBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATantrumCharacterBase_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATantrumCharacterBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumCharacterBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATantrumCharacterBase()
	{
		if (!Z_Registration_Info_UClass_ATantrumCharacterBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATantrumCharacterBase.OuterSingleton, Z_Construct_UClass_ATantrumCharacterBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATantrumCharacterBase.OuterSingleton;
	}
	template<> TANTRUM_API UClass* StaticClass<ATantrumCharacterBase>()
	{
		return ATantrumCharacterBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATantrumCharacterBase);
	ATantrumCharacterBase::~ATantrumCharacterBase() {}
	struct Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::EnumInfo[] = {
		{ ECharacterThrowState_StaticEnum, TEXT("ECharacterThrowState"), &Z_Registration_Info_UEnum_ECharacterThrowState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 260039719U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATantrumCharacterBase, ATantrumCharacterBase::StaticClass, TEXT("ATantrumCharacterBase"), &Z_Registration_Info_UClass_ATantrumCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATantrumCharacterBase), 2986990622U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_2533154133(TEXT("/Script/Tantrum"),
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumCharacterBase_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
