#pragma once
#include "../shared.hpp"
#include "shared/functions.hpp"

namespace intercept {
    namespace client {








        class host {
        public:
            static client_functions functions;
            static r_string module_name;
           

            ///@copydoc intercept::sqf_functions::registerFunction(std::string_view, std::string_view, WrapperFunctionBinary, types::GameDataType, types::GameDataType, types::GameDataType)
            [[nodiscard]] static registered_sqf_function registerFunction(std::string_view name, std::string_view description, WrapperFunctionBinary function_, types::GameDataType return_arg_type, types::GameDataType left_arg_type, types::GameDataType right_arg_type);

            ///@copydoc intercept::sqf_functions::registerFunction(std::string_view, std::string_view, WrapperFunctionUnary, types::GameDataType, types::GameDataType)
            [[nodiscard]] static registered_sqf_function registerFunction(std::string_view name, std::string_view description, WrapperFunctionUnary function_, types::GameDataType return_arg_type, types::GameDataType right_arg_type);

            ///@copydoc intercept::sqf_functions::registerFunction(std::string_view, std::string_view, WrapperFunctionNular, types::GameDataType)
            [[nodiscard]] static registered_sqf_function registerFunction(std::string_view name, std::string_view description, WrapperFunctionNular function_, types::GameDataType return_arg_type);
            
            ///@copydoc intercept::sqf_functions::registerType
            [[nodiscard]] static std::pair<types::GameDataType, sqf_script_type> registerType(std::string_view name, std::string_view localizedName, std::string_view description, std::string_view typeName, script_type_info::createFunc cf);

            ///@copydoc intercept::extensions::register_plugin_interface
            static register_plugin_interface_result register_plugin_interface(std::string_view name_, uint32_t api_version_, void* interface_class_);
            ///@copydoc intercept::extensions::list_plugin_interfaces
            static std::pair<r_string, auto_array<uint32_t>> list_plugin_interfaces(std::string_view name_);
            ///@copydoc intercept::extensions::request_plugin_interface
            static std::optional<void*> request_plugin_interface(std::string_view name_, uint32_t api_version_);


        };


        
        extern "C" {
            /// @private
            DLLEXPORT void CDECL assign_functions(const struct client_functions funcs, r_string module_name);
        }
        /// @private
        void __initialize();

        class invoker_lock {
        public:
            explicit invoker_lock(bool delayed_ = false);
            invoker_lock(const invoker_lock &) = delete;
            invoker_lock(invoker_lock &&) = delete;
            invoker_lock & operator=(const invoker_lock &) = delete;
            invoker_lock & operator=(invoker_lock &&) = delete;
            ~invoker_lock();
            void lock();
            void unlock();
        protected:
            bool _locked;
        };
    }


}
