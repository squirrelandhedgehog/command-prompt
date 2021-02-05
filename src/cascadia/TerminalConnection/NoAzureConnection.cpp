// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

#include "pch.h"
#include "AzureConnection.g.h"

#include "../cascadia/inc/cppwinrt_utils.h"
#include "ConnectionStateHolder.h"

namespace winrt::Microsoft::Terminal::TerminalConnection::implementation
{
    struct AzureConnection : AzureConnectionT<AzureConnection>, ConnectionStateHolder<AzureConnection>
    {
        static winrt::guid ConnectionType() noexcept
        {
            static constexpr winrt::guid AzureConnectionType = { 0xd9fcfdfa, 0xa479, 0x412c, { 0x83, 0xb7, 0xc5, 0x64, 0xe, 0x61, 0xcd, 0x62 } };
            return AzureConnectionType;
        }
        static bool IsAzureConnectionAvailable() noexcept { return false; }
        AzureConnection(const uint32_t /*rows*/, const uint32_t /*cols*/) {}

        void Start() {}
        void WriteInput(hstring const& /*data*/) {}
        void Resize(uint32_t /*rows*/, uint32_t /*columns*/) {}
        void Close() {}

        WINRT_CALLBACK(TerminalOutput, TerminalOutputHandler);
    };
}

namespace winrt::Microsoft::Terminal::TerminalConnection::factory_implementation
{
    struct AzureConnection : AzureConnectionT<AzureConnection, implementation::AzureConnection>
    {
    };
}

#include "AzureConnection.g.cpp"
