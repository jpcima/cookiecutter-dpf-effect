/*
 * {{ cookiecutter.project_name }} audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: {{ cookiecutter.project_license }}
 *
 * Copyright (C) {{ cookiecutter.year }} {{ cookiecutter.author_name }} <{{ cookiecutter.email }}>
{%- if cookiecutter.project_license == 'MIT' %}
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
{%- endif %}
 */

#ifndef DISTRHO_PLUGIN_INFO_H
#define DISTRHO_PLUGIN_INFO_H

#define DISTRHO_PLUGIN_BRAND "{{ cookiecutter.plugin_brand }}"
#define DISTRHO_PLUGIN_NAME  "{{ cookiecutter.plugin_name }}"
#define DISTRHO_PLUGIN_URI   "{{ cookiecutter.plugin_uri }}"

#define DISTRHO_PLUGIN_HAS_UI        {{ 0 if cookiecutter.ui_type == "none" else 1 }}
#define DISTRHO_UI_USE_NANOVG        {{ 1 if cookiecutter.ui_type == "nanovg" else 0 }}

#define DISTRHO_PLUGIN_IS_RT_SAFE    1
#define DISTRHO_PLUGIN_NUM_INPUTS    2
#define DISTRHO_PLUGIN_NUM_OUTPUTS   2
#define DISTRHO_PLUGIN_WANT_TIMEPOS  0
#define DISTRHO_PLUGIN_WANT_PROGRAMS 1

#endif // DISTRHO_PLUGIN_INFO_H
