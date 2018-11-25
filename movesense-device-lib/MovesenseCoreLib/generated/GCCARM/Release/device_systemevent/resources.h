#pragma once
/***********************************************************************
* THIS FILE HAS BEEN GENERATED BY WBRES TOOL. DO NOT TRY TO CHANGE IT. *
***********************************************************************/
// Copyright (c) Suunto Oy 2014 - 2017. All rights reserved.

#include "whiteboard/Identifiers.h"
#include "whiteboard/ParameterList.h"
#include "whiteboard/Result.h"
#include "whiteboard/ResourceClient.h"

#include "whiteboard/builtinTypes/Array.h"
#include "whiteboard/builtinTypes/ByteStream.h"
#include "whiteboard/builtinTypes/Date.h"
#include "whiteboard/builtinTypes/DateTime.h"
#include "whiteboard/builtinTypes/Optional.h"
#include "whiteboard/builtinTypes/Structures.h"
#include "whiteboard/builtinTypes/Time.h"
#include "whiteboard/builtinTypes/Timestamp.h"
#include "whiteboard/builtinTypes/TypedEnum.h"
#include "whiteboard/builtinTypes/Vector2D.h"
#include "whiteboard/builtinTypes/Vector3D.h"
#include "whiteboard/builtinTypes/WrapperFor32BitPointer.h"

#define WB_RESOURCE_VALUE(whiteboardId, localResourceId, executionContextId) \
    static_cast<whiteboard::ResourceId::Value>( \
        (static_cast<uint32>(localResourceId) << 16) | \
        (static_cast<uint32>(whiteboardId) << 8) | \
        (static_cast<uint32>(executionContextId) << 4) | \
        (static_cast<uint32>(whiteboard::ID_INVALID_RESOURCE_INSTANCE)))


#include "../wb-resources/resources.h"
#include "../movesense_types/resources.h"

#define WB_EXEC_CTX_APPLICATION                  static_cast<whiteboard::ExecutionContextId>(0)
#define WB_EXEC_CTX_MEAS                         static_cast<whiteboard::ExecutionContextId>(1)

namespace WB_RES {

struct WB_ALIGN(4) SystemEventLogEntry;
struct WB_ALIGN(4) SystemEventLogEntryArray;

struct WB_ALIGN(4) SystemEventLogEntry
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 1536;

	WB_ALIGN(4) uint32 sequenceNumber;
	WB_ALIGN(4) whiteboard::WrapperFor32BitPointer<const char> event;
	WB_ALIGN(2) uint16 compoundSystemState;
	WB_ALIGN(4) uint32 timestamp;
	WB_ALIGN(2) uint16 moduleID;
};

struct WB_ALIGN(4) SystemEventLogEntryArray
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 1537;

	WB_ALIGN(4) whiteboard::Array< SystemEventLogEntry > events;
};

namespace LOCAL 
{

struct ROOT;

struct DEVICE;

struct DEVICE_SYSTEMEVENT
{
	static const whiteboard::ExecutionContextId EXECUTION_CONTEXT = WB_EXEC_CTX_MEAS;
	static const whiteboard::ResourceId::Value ID = WB_RESOURCE_VALUE(0, 1536, EXECUTION_CONTEXT);
	static const whiteboard::LocalResourceId LID = 1536;

	struct GET
	{
		typedef whiteboard::StronglyTypedResult<const SystemEventLogEntryArray&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;

		struct Parameters
		{
			struct SEQUENCENUMBER
			{
				static const whiteboard::ParameterIndex Index = 0;

				typedef uint32 Type;
				typedef Type ConstReferenceType;
			};

			typedef SEQUENCENUMBER Parameter1;

			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 1;
		};

		/** Reference wrapper for strongly typed parameter list for /Device/SystemEvent */
		class ParameterListRef
		{
		private:
			/** Prevent use of default constructor */
			ParameterListRef() DELETED;

			/** Prevent use of copy constructor */
			ParameterListRef(const ParameterListRef&) DELETED;

			/** Prevent use of assignment operator */
			const ParameterListRef& operator=(const ParameterListRef&) DELETED;

		public:
			/** Constructor that initializes this class from existing parameter list
			*
			* @param rParameterList Reference to parameter list that contains untyped parameters
			*/
			inline ParameterListRef(const whiteboard::ParameterList& rParameterList)
				: mrParameterList(rParameterList)
			{
			}

			/** Checks whether optional parameter SEQUENCENUMBER has a value
			*
			* @return A value indicating whether the parameter has a value
			*/
			inline bool hasSequenceNumber() const
			{
				if (mrParameterList.getNumberOfParameters() <= Parameters::SEQUENCENUMBER::Index)
				{
					return false;
				}

				return mrParameterList[Parameters::SEQUENCENUMBER::Index].getType() != whiteboard::WB_TYPE_NONE;
			}

			/** Gets SEQUENCENUMBER parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::SEQUENCENUMBER::ConstReferenceType getSequenceNumber() const
			{
				return mrParameterList[Parameters::SEQUENCENUMBER::Index].convertTo<Parameters::SEQUENCENUMBER::ConstReferenceType>();
			}

		private:
			/** Reference to actual parameter list */
			const whiteboard::ParameterList& mrParameterList;
		};

		/** Compile time type checking */
		inline static void typeCheck(
			const whiteboard::Api::OptionalParameter<Parameters::SEQUENCENUMBER::ConstReferenceType>& = whiteboard::NoType::NoValue)
		{
		}
	};
};



} // namespace LOCAL 

} // namespace WB_RES