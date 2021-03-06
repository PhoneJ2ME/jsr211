#
#   
#
# Copyright  1990-2007 Sun Microsystems, Inc. All Rights Reserved.
# DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License version
# 2 only, as published by the Free Software Foundation.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License version 2 for more details (a copy is
# included at /legal/license.txt).
# 
# You should have received a copy of the GNU General Public License
# version 2 along with this work; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
# 02110-1301 USA
# 
# Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
# Clara, CA 95054 or visit www.sun.com if you need additional
# information or have any questions.
#
######################################################################
#
# Module's Component Configuration file
#
#####################################################################


# Directory containing application specific native files
SUBSYSTEM_JSR_211_APPLICATION_NATIVE_DIR = $(JSR_211_DIR)/src/osgi_application/core/native/

SUBSYSTEM_JSR_211_APPLICATION_CLASSES_DIR = $(JSR_211_DIR)/src/osgi_application/classes/

# 
# depeneds on 
# OSGI_DEMO_CLASSES_DIR
# OSGI_BUNDLES_DIR
# INTERNAL_JSR_211_APPLICATION_DIR

JSR211_OSGI_BRIDGE_APPLICATION_NAME = jsr211_agent

JSR211_BRIDGE_CLASSES_DIR ?= $(OSGI_DEMO_CLASSES_DIR)/$(JSR211_OSGI_BRIDGE_APPLICATION_NAME)

JSR211_BRIDGE_JAVA_FILES = \
  $(INTERNAL_JSR_211_APPLICATION_DIR)/com/sun/j2me/content/osgi/JSR211Service.java \
  $(INTERNAL_JSR_211_APPLICATION_DIR)/com/sun/j2me/content/osgi/CHAPIBridgeFactory.java \

JSR211_BRIDGE_MANIFEST = $(INTERNAL_JSR_211_APPLICATION_DIR)/com/sun/j2me/content/osgi/manifest.mf

JSR211_BRIDGE_CLASSES = $(OSGI_DEMO_CLASSES_DIR)/$(JSR211_OSGI_BRIDGE_APPLICATION_NAME)

JSR211_BRIDGE_JAR = $(OSGI_BUNDLES_DIR)/$(JSR211_OSGI_BRIDGE_APPLICATION_NAME).jar

OSGI_DEMO_JARS += $(JSR211_BRIDGE_JAR)
	