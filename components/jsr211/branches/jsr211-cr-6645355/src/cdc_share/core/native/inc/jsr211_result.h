
/*
 * 
 *
 * Copyright  1990-2007 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation. 
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt). 
 * 
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA 
 * 
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions. 
 */

/*
 * @(#)jsr211_result.h	1.18 06/04/05 @(#)
 */

/**
 * @file
 * @defgroup chapi JSR 211 Content Handler API (CHAPI)
 * @ingroup msa
 * @brief This is the API definition for content handler registry query results presentation
  * @{
 * Defines structures that manages memory allocation and
 * collect results of registry queries in special normalized form.
 */

#ifndef _JSR211_RESULT_H_
#define _JSR211_RESULT_H_

#ifdef __cplusplus
extern "C" {
#endif/*__cplusplus*/

/**
 * Functions results enumeration
 */
typedef enum {
  JSR211_OK = 0,       /**< A function finished without errors */
  JSR211_FAILED    /**< An error occured */
} jsr211_result;

/**
 * Boolean enumeration
 */
typedef enum {
  JSR211_FALSE = 0,    /**< False value */
  JSR211_TRUE      /**< True value */
} jsr211_boolean;

#ifndef jchar
typedef unsigned short jchar;
#endif

/**
 * Common result buffer for serialized data storage.
 */
typedef void* JSR211_RESULT_BUFFER;

/**
 * Result buffer for Content Handler. Use @link jsr211_fillHandler function to 
 * fill this structure.
 */
typedef JSR211_RESULT_BUFFER JSR211_RESULT_CH;

/**
 * Result buffer for Content Handlers array. Use @link jsr211_appendHandler
 * function to fill this structure.
 */
typedef JSR211_RESULT_BUFFER JSR211_RESULT_CHARRAY;

/**
 * Result buffer for string array. Use @link jsr211_appendString
 * function to fill this structure.
 */
typedef JSR211_RESULT_BUFFER JSR211_RESULT_STRARRAY;

/**
 * Creates and initialize new result buffer
 * @return pointer to new result buffer or zero if no memory available
 */
JSR211_RESULT_BUFFER jsr211_create_result_buffer();

/**
 * Clean and release result buffer allocated with create_res_buffer
 * @param resbuf result handle
 * @return nothing
 */
void jsr211_release_result_buffer(JSR211_RESULT_BUFFER resbuf);

/**
 * Retrieve data pointer from result buffer or zero if no result was allocated
 * @param resbuf result handle
 * @return constant pointer to result data
 */
const jchar* jsr211_get_result_data(JSR211_RESULT_BUFFER resbuf);

/**
 * Retrieve length of result data in jchar units
 * @param resbuf result handle
 * @return operation status.
 */
int jsr211_get_result_data_length(JSR211_RESULT_BUFFER resbuf);


/**
 * Fills output result structure with handler data.
 * @param id handler ID
 * @param id_size handler ID size
 * @param suit suite Id
 * @param class_name handler class name
 * @param class_name_size handler class name size
 * @param flag handler installation flag
 * @param result output result structure.
 * @return operation status.
 */
jsr211_result jsr211_fillHandler(
        const jchar* id, int id_size,
		int suite_id,
        const jchar* class_name, int class_name_size,
        int flag, /*OUT*/ JSR211_RESULT_CH result);


/**
 * Appends string to output string array.
 * @param str appended string
 * @param str_size the string size
 * @param array string array.
 * @return operation status.
 */
jsr211_result jsr211_appendString(
        const jchar* str, int str_size,
        /*OUT*/ JSR211_RESULT_STRARRAY array);

/**
 * Tests if the string is not identical to any of ones included in array.
 * @param str appended string
 * @param str_size the string size
 * @param casesens should comparison be case sensitive
 * @param array string array.
 * @return JSR211_TRUE if string does not present in result yet JSR211_FALSE if does
 */
jsr211_boolean jsr211_isUniqueString(const jchar *str, int sz, int casesens, JSR211_RESULT_STRARRAY array);

/**
 * Appends string to output string array if it is not already in array.
 * @param str appended string
 * @param str_size the string size
 * @param casesens should comparison be case sensitive
 * @param array string array.
 * @return operation status.
 */
jsr211_result jsr211_appendUniqueString(const jchar* str, int str_size, int casesens,
												  /*OUT*/ JSR211_RESULT_STRARRAY array);

/**
 * Tests if the handler id is not identical to any of ones included in content handler array.
 * @param id tested content handler id 
 * @param id_sz the id size in jchars
 * @param array array of content handlers.
 * @return JSR211_TRUE if id does not present in result yet JSR211_FALSE if does
 */
jsr211_boolean jsr211_isUniqueHandler(const jchar *id, int id_sz,
									  JSR211_RESULT_CHARRAY array);

/**
 * Appends the handler data to the result array.
 * @param id handler ID
 * @param id_size handler ID size
 * @param suit suite Id
 * @param class_name handler class name
 * @param class_name_size handler class name size
 * @param flag handler installation flag
 * @param array output result array.
 * @return operation status.
 */
jsr211_result jsr211_appendHandler(
        const jchar* id, int id_size,
		int suite_id,
        const jchar* class_name, int class_name_size,
        int flag, /*OUT*/ JSR211_RESULT_CHARRAY array);



/** @} */

#ifdef __cplusplus
}
#endif/*__cplusplus*/

#endif  /* _JSR211_REGISTRY_H_ */