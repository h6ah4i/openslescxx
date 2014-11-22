//
//    Copyright (C) 2014 Haruki Hasegawa
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#ifndef OPENSLESCXX_CSL_INTERFACE_HPP_
#define OPENSLESCXX_CSL_INTERFACE_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>

namespace opensles {

//
// Base Inetrface Class
//
class CSLInterface {
public:
    explicit CSLInterface(const SLInterfaceID &iid) : iid_(iid), self_(nullptr) {}
    virtual ~CSLInterface() {}

    const SLInterfaceID getIID() const noexcept { return iid_; }
    void const **rawPtrEntity() noexcept { return &self_; }
    void const *const *rawPtrEntity() const noexcept { return &self_; }

    // inhibit copy operations
    CSLInterface(const CSLInterface &) = delete;
    CSLInterface &operator=(const CSLInterface &) = delete;

    operator bool() const noexcept { return (self_) ? true : false; }

    void unbind() noexcept
    {
        if (self_) {
            onDetachEntity(true);
        }
    }

    void assign(const void *entity) noexcept
    {
        if (self_) {
            onDetachEntity(false);
        }
        if (entity) {
            onAttachEntity(entity);
        }
    }

    virtual const char *name() noexcept { return "CSLInterface"; }

protected:
    virtual void onMove(CSLInterface &other) noexcept
    {
        if (self_) {
            onDetachEntity(false);
        }
        if (other.self_) {
            onAttachEntity(other.self_);
        }
        if (other.self_) {
            other.onDetachEntity(true);
        }
    }

    virtual void onAttachEntity(const void *entity) noexcept { self_ = entity; }

    virtual void onDetachEntity(bool unbind) noexcept { self_ = nullptr; }

private:
    const SLInterfaceID iid_;
    const void *self_;
};

#define DECL_CSL_INTERFACE_OPERATORS(Tself, Tentity)                                                                   \
    virtual const char *name() noexcept override { return #Tself; }                                                    \
                                                                                                                       \
    Tentity &self() noexcept { return *(reinterpret_cast<Tentity *>(rawPtrEntity())); }                                \
                                                                                                                       \
    const Tentity &self() const noexcept { return *(reinterpret_cast<const Tentity *>(rawPtrEntity())); }              \
                                                                                                                       \
    Tself &operator=(Tself &&other) noexcept                                                                           \
    {                                                                                                                  \
        if (&other == this) {                                                                                          \
            return (*this);                                                                                            \
        }                                                                                                              \
        onMove(other);                                                                                                 \
        return (*this);                                                                                                \
    }

} // namespace opensles

#endif // OPENSLESCXX_CSL_INTERFACE_HPP_
