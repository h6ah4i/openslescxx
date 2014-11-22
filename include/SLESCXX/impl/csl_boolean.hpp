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

#ifndef OPENSLESCXX_CSL_BOOLEAN_HPP_
#define OPENSLESCXX_CSL_BOOLEAN_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>

namespace opensles {

//
// Boolean
//
class CSLboolean {
public:
    CSLboolean() : value_(SL_BOOLEAN_FALSE) {}

    CSLboolean(SLboolean value) : value_(value) {}

    operator SLboolean() const noexcept { return value_; }

    operator bool() const noexcept { return toCpp(value_); }

    CSLboolean &operator=(const CSLboolean &value) noexcept
    {
        value_ = value.value_;
        return *this;
    }

    CSLboolean &operator=(SLboolean value) noexcept
    {
        value_ = value;
        return *this;
    }

    CSLboolean &operator=(bool value) noexcept
    {
        value_ = toSL(value);
        return *this;
    }

    static bool toCpp(SLboolean value) noexcept { return value ? true : false; }

    static bool toSL(bool value) noexcept { return value ? SL_BOOLEAN_TRUE : SL_BOOLEAN_FALSE; }

private:
    SLboolean value_;
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_BOOLEAN_HPP_
