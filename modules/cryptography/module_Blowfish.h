/**************************************************************************/
/*  module_Blowfish.h                                                     */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             REDOT ENGINE                               */
/*                        https://redotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2024-present Redot Engine contributors                   */
/*                                          (see REDOT_AUTHORS.md)        */
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef MODULE_BLOWFISH_H
#define MODULE_BLOWFISH_H

#include <core/object/ref_counted.h>
#include <core/variant/variant.h>

#ifdef __has_include
#if __has_include(<openssl/blowfish.h>)
#include <openssl/blowfish.h>
#include <openssl/rand.h>
#endif
#endif

#include <vector>

class module_Blowfish : public Object {
	GDCLASS(module_Blowfish, Object);

#ifdef __has_include
#if __has_include(<openssl/blowfish.h>)
private:
	EVP_CIPHER_CTX *ctx;
	std::vector<uint8_t> iv;
#endif
#endif

public:
	static void _bind_methods();
	module_Blowfish();
	~module_Blowfish();
	bool generate_key(size_t bytes);
	String encrypt(String plaintext);
	String decrypt(String ciphertext);
};

#endif // MODULE_BLOWFISH_H
