// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TantrumGameModeBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EGameState : uint8;
#ifdef TANTRUM_TantrumGameModeBase_generated_h
#error "TantrumGameModeBase.generated.h already included, missing '#pragma once' in TantrumGameModeBase.h"
#endif
#define TANTRUM_TantrumGameModeBase_generated_h

#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_SPARSE_DATA
#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentGameState);


#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_ACCESSORS
#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATantrumGameModeBase(); \
	friend struct Z_Construct_UClass_ATantrumGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ATantrumGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tantrum"), NO_API) \
	DECLARE_SERIALIZER(ATantrumGameModeBase)


#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATantrumGameModeBase(ATantrumGameModeBase&&); \
	NO_API ATantrumGameModeBase(const ATantrumGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATantrumGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATantrumGameModeBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATantrumGameModeBase) \
	NO_API virtual ~ATantrumGameModeBase();


#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_22_PROLOG
#define FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_SPARSE_DATA \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_ACCESSORS \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_INCLASS_NO_PURE_DECLS \
	FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANTRUM_API UClass* StaticClass<class ATantrumGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Tantrum_Source_Tantrum_TantrumGameModeBase_h


#define FOREACH_ENUM_EGAMESTATE(op) \
	op(EGameState::NONE) \
	op(EGameState::Waiting) \
	op(EGameState::Playing) \
	op(EGameState::Paused) \
	op(EGameState::GameOver) 

enum class EGameState : uint8;
template<> struct TIsUEnumClass<EGameState> { enum { Value = true }; };
template<> TANTRUM_API UEnum* StaticEnum<EGameState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
