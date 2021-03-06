// Copyright (c) 2020 Tom Hancocks
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#if !defined(PHOTON_STATUS_CODE_HPP)
#define PHOTON_STATUS_CODE_HPP

namespace photon::http
{
    enum status_code : int
    {
        // 1xx
        continue_code = 100,
        switching_protocols = 101,
        processing = 102,
        early_hints = 103,

        // 2xx
        ok = 200,
        created = 201,
        accepted = 202,
        non_authoritative_information = 203,
        no_content = 204,
        reset_content = 205,
        partial_content = 206,
        multi_status = 207,
        already_reported = 208,
        im_used = 226,

        // 3xx
        multiple_choices = 300,
        moved_permanently = 301,
        found = 302,
        see_other = 303,
        not_modified = 304,
        use_proxy = 305,
        switch_proxy = 306,
        temporary_redirect = 307,
        permanent_redirect = 308,

        // 4xx
        bad_request = 400,
        unauthorised = 401,
        payment_required = 402,
        forbidden = 403,
        not_found = 404,
        method_not_allowed = 405,
        not_acceptable = 406,
        proxy_authentication_required = 407,
        request_timeout = 408,
        conflict = 409,
        gone = 410,
        length_required = 411,
        precondition_failed = 412,
        payload_too_large = 413,
        uri_too_long = 414,
        unsupported_media_type = 415,
        range_not_satisfiable = 416,
        expectation_failed = 417,
        im_a_teapot = 418,
        misdirected_request = 421,
        unprocessable_entity = 422,
        locked = 423,
        failed_dependency = 424,
        too_early = 425,
        upgrade_required = 426,
        precondition_required = 428,
        too_many_requests = 429,
        request_header_fields_too_large = 431,
        unavailable_for_legal_reasons = 451,

        // 5xx
        internal_server_error = 500,
        not_implemented = 501,
        bad_gateway = 502,
        service_unavailable = 503,
        gateway_timeout = 504,
        http_version_not_supported = 505,
        variant_also_negotiates = 506,
        insufficient_storage = 507,
        loop_detected = 508,
        not_extended = 510,
        network_authentication_required = 511
    };
}

#endif //PHOTON_STATUS_CODE_HPP
