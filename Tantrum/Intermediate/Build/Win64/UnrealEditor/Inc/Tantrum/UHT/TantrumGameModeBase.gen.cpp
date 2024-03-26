// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tantrum/TantrumGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTantrumGameModeBase() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumGameModeBase();
	TANTRUM_API UClass* Z_Construct_UClass_ATantrumGameModeBase_NoRegister();
	TANTRUM_API UClass* Z_Construct_UClass_UTantrumGameWidget_NoRegister();
	TANTRUM_API UEnum* Z_Construct_UEnum_Tantrum_EGameState();
	UPackage* Z_Construct_UPackage__Script_Tantrum();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGameState;
	static UEnum* EGameState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EGameState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EGameState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Tantrum_EGameState, (UObject*)Z_Construct_UPackage__Script_Tantrum(), TEXT("EGameState"));
		}
		return Z_Registration_Info_UEnum_EGameState.OuterSingleton;
	}
	template<> TANTRUM_API UEnum* StaticEnum<EGameState>()
	{
		return EGameState_StaticEnum();
	}
	struct Z_Construct_UEnum_Tantrum_EGameState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Tantrum_EGameState_Statics::Enumerators[] = {
		{ "EGameState::NONE", (int64)EGameState::NONE },
		{ "EGameState::Waiting", (int64)EGameState::Waiting },
		{ "EGameState::Playing", (int64)EGameState::Playing },
		{ "EGameState::Paused", (int64)EGameState::Paused },
		{ "EGameState::GameOver", (int64)EGameState::GameOver },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Tantrum_EGameState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Enum to track the current state of the game\n" },
#endif
		{ "GameOver.DisplayName", "GameOver" },
		{ "GameOver.Name", "EGameState::GameOver" },
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
		{ "NONE.DisplayName", "None" },
		{ "NONE.Name", "EGameState::NONE" },
		{ "Paused.DisplayName", "Paused" },
		{ "Paused.Name", "EGameState::Paused" },
		{ "Playing.DisplayName", "Playing" },
		{ "Playing.Name", "EGameState::Playing" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enum to track the current state of the game" },
#endif
		{ "Waiting.DisplayName", "Waiting" },
		{ "Waiting.Name", "EGameState::Waiting" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Tantrum_EGameState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Tantrum,
		nullptr,
		"EGameState",
		"EGameState",
		Z_Construct_UEnum_Tantrum_EGameState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Tantrum_EGameState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Tantrum_EGameState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Tantrum_EGameState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Tantrum_EGameState()
	{
		if (!Z_Registration_Info_UEnum_EGameState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGameState.InnerSingleton, Z_Construct_UEnum_Tantrum_EGameState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EGameState.InnerSingleton;
	}
	DEFINE_FUNCTION(ATantrumGameModeBase::execGetCurrentGameState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EGameState*)Z_Param__Result=P_THIS->GetCurrentGameState();
		P_NATIVE_END;
	}
	void ATantrumGameModeBase::StaticRegisterNativesATantrumGameModeBase()
	{
		UClass* Class = ATantrumGameModeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCurrentGameState", &ATantrumGameModeBase::execGetCurrentGameState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics
	{
		struct TantrumGameModeBase_eventGetCurrentGameState_Parms
		{
			EGameState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TantrumGameModeBase_eventGetCurrentGameState_Parms, ReturnValue), Z_Construct_UEnum_Tantrum_EGameState, METADATA_PARAMS(0, nullptr) }; // 3067675615
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATantrumGameModeBase, nullptr, "GetCurrentGameState", nullptr, nullptr, Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::TantrumGameModeBase_eventGetCurrentGameState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::TantrumGameModeBase_eventGetCurrentGameState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATantrumGameModeBase);
	UClass* Z_Construct_UClass_ATantrumGameModeBase_NoRegister()
	{
		return ATantrumGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATantrumGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentGameState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentGameState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentGameState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameCountdownDuration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GameCountdownDuration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GameWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameWidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_GameWidgetClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATantrumGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Tantrum,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ATantrumGameModeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATantrumGameModeBase_GetCurrentGameState, "GetCurrentGameState" }, // 214032234
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TantrumGameModeBase.h" },
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState_MetaData[] = {
		{ "Category", "States" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Create and set CUrrentGameState to NONE. This will be tracked in the code file.\n" },
#endif
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Create and set CUrrentGameState to NONE. This will be tracked in the code file." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState = { "CurrentGameState", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumGameModeBase, CurrentGameState), Z_Construct_UEnum_Tantrum_EGameState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState_MetaData), Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState_MetaData) }; // 3067675615
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameCountdownDuration_MetaData[] = {
		{ "Category", "Game Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Countdown before gameplay state begins. Exposed so we can easily change this in BP editor.\n" },
#endif
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Countdown before gameplay state begins. Exposed so we can easily change this in BP editor." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameCountdownDuration = { "GameCountdownDuration", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumGameModeBase, GameCountdownDuration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameCountdownDuration_MetaData), Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameCountdownDuration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidget = { "GameWidget", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumGameModeBase, GameWidget), Z_Construct_UClass_UTantrumGameWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidget_MetaData), Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidgetClass_MetaData[] = {
		{ "Category", "Widget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Object we'll be creating and addin to the viewport\n" },
#endif
		{ "ModuleRelativePath", "TantrumGameModeBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Object we'll be creating and addin to the viewport" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidgetClass = { "GameWidgetClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATantrumGameModeBase, GameWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UTantrumGameWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidgetClass_MetaData), Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidgetClass_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATantrumGameModeBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_CurrentGameState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameCountdownDuration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATantrumGameModeBase_Statics::NewProp_GameWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATantrumGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATantrumGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATantrumGameModeBase_Statics::ClassParams = {
		&ATantrumGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATantrumGameModeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATantrumGameModeBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATantrumGameModeBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATantrumGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ATantrumGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATantrumGameModeBase.OuterSingleton, Z_Construct_UClass_ATantrumGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATantrumGameModeBase.OuterSingleton;
	}
	template<> TANTRUM_API UClass* StaticClass<ATantrumGameModeBase>()
	{
		return ATantrumGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATantrumGameModeBase);
	ATantrumGameModeBase::~ATantrumGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics::EnumInfo[] = {
		{ EGameState_StaticEnum, TEXT("EGameState"), &Z_Registration_Info_UEnum_EGameState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3067675615U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATantrumGameModeBase, ATantrumGameModeBase::StaticClass, TEXT("ATantrumGameModeBase"), &Z_Registration_Info_UClass_ATantrumGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATantrumGameModeBase), 815300994U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_3420669516(TEXT("/Script/Tantrum"),
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
