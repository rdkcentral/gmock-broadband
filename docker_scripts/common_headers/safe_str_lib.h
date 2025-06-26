#define EOK 0
#define ESNULLP          400        /* null ptr                    */
#define ESLEMAX          403       /* length exceeds RSIZE_MAX    */
#define ESNOSPC          406       /* not enough space for dest     */

#ifndef errno_t
typedef int errno_t;
#endif

#define ERR_CHK(rc)                                             \
      if(rc !=EOK) {                                              \
          RDK_SAFECLIB_ERR(rc);                                   \
      }
#define strcat_s(dest, dmax, src) _strcat_s_chk(dest, dmax, src, dest)
#define strcpy_s(dest, dmax, src) _strcpy_s_chk(dest, dmax, src, dest)
#define strncat_s(dest, dmax, src, slen) _strncat_s_chk(dest, dmax, src, slen, dest, src)
#define strncpy_s(dest, dmax, src, slen) _strncpy_s_chk(dest, dmax, src, slen, dest, src)
#define strnlen_s(str, smax) _strnlen_s_chk(str, smax, str)
#define strtok_s(dest, dmaxp, delim, ptr) _strtok_s_chk(dest, dmaxp, delim, ptr, dest)
#define sprintf_s(dest, dmax, ...) _sprintf_s_chk(dest, dmax, dest, __VA_ARGS__)
#define vsprintf_s(dest, dmax, fmt, ap) _vsprintf_s_chk(dest, dmax, dest, fmt, ap)
#define snprintf_s(dest, dmax, ...) _sprintf_s_chk(dest, dmax, dest, __VA_ARGS__)
#define vsnprintf_s(dest, dmax, fmt, ap) _vsnprintf_s_chk(dest, dmax, dest, fmt, ap)
#define strerror_s(dest, dmax, errnum) _strerror_s_chk(dest, dmax, errnum, dest)
#define strcmp_s(dest, dmax, src, resultp) _strcmp_s_chk(dest, dmax, src, resultp, dest, src)
#define strcasecmp_s(dest, dmax, src, resultp) _strcasecmp_s_chk(dest, dmax, src, resultp, dest)
#define strnatcmp_s(dest, dmax, src, resultp) _strnatcmp_s_chk(dest, dmax, src, 0, resultp, dest, src)
#define strnatcasecmp_s(dest, dmax, src, resultp) _strnatcasecmp_s_chk(dest, dmax, src, 1, resultp, dest, src)
#define strcasestr_s(dest, dmax, src, slen, substring) _strcasestr_s_chk(dest, dmax, src, slen, substring, dest, src)
#define strcmpfld_s(dest, dmax, src, resultp) _strcmpfld_s_chk(dest, dmax, src, resultp, dest, src)
#define strcpyfld_s(dest, dmax, src, slen) _strcpyfld_s_chk(dest, dmax, src, slen, dest, src)
#define strcpyfldin_s(dest, dmax, src, slen) _strcpyfldin_s_chk(dest, dmax, src, slen, dest, src)
#define strcpyfldout_s(dest, dmax, src, slen)  _strcpyfldout_s_chk(dest, dmax, src, slen, dest, src)
#define strcspn_s(dest, dmax, src, slen, countp) _strcspn_s_chk(dest, dmax, src, slen, countp, dest, src)
#define strfirstchar_s(dest, dmax, c, firstp) _strfirstchar_s_chk(dest, dmax, c, firstp, dest)
#define strfirstdiff_s(dest, dmax, src, resultp) _strfirstdiff_s_chk(dest, dmax, src, resultp, dest)
#define strisalphanumeric_s(dest, dmax) _strisalphanumeric_s_chk(dest, dmax, dest)
#define strisascii_s(dest, dmax) _strisascii_s_chk(dest, dmax, dest)
#define strisdigit_s(dest, dmax) _strisdigit_s_chk(dest, dmax, dest)
#define strishex_s(dest, dmax) _strishex_s_chk(dest, dmax, dest)
#define strislowercase_s(dest, dmax) _strislowercase_s_chk(dest, dmax, dest)
#define strismixedcase_s(dest, dmax) _strismixedcase_s_chk(dest, dmax, dest)
#define strispassword_s(dest, dmax) _strispassword_s_chk(dest, dmax, dest)
#define strisuppercase_s(dest, dmax) _strisuppercase_s_chk(dest, dmax, dest)
#define strlastchar_s(dest, dmax, c, lastp) _strlastchar_s_chk(dest, dmax, c, lastp, dest)
#define strlastdiff_s(dest, dmax, src, resultp) _strlastdiff_s_chk(dest, dmax, src, resultp, dest)
#define strljustify_s(dest, dmax) _strljustify_s_chk(dest, dmax, dest)
#define strnterminate_s(dest, dmax) _strnterminate_s_chk(dest, dmax, dest)
#define strpbrk_s(dest, dmax, src, slen, firstp) _strpbrk_s_chk(dest, dmax, src, slen, firstp, dest, src)
#define strfirstsame_s(dest, dmax, src, resultp) _strfirstsame_s_chk(dest, dmax, src, resultp, dest)
#define strlastsame_s(dest, dmax, src, resultp) _strlastsame_s_chk(dest, dmax, src, resultp, dest)
#define strprefix_s(dest, dmax, src) _strprefix_s_chk(dest, dmax, src, dest)
#define strremovews_s(dest, dmax) _strremovews_s_chk(dest, dmax, dest)
#define strspn_s(dest, dmax, src, slen, countp) _strspn_s_chk(dest, dmax, src, slen, countp, dest, src)
#define strstr_s(dest, dmax, src, slen, substringp) _strstr_s_chk(dest, dmax, src, slen, substringp, dest, src)
#define strchr_s(dest, dmax, ch, resultp) _strchr_s_chk(dest, dmax, ch, resultp, dest)
#define strrchr_s(dest, dmax, ch, resultp) _strrchr_s_chk(dest, dmax, ch, resultp, dest)
#define strtolowercase_s(dest, dmax) _strtolowercase_s_chk(dest, dmax, dest)
#define strtouppercase_s(dest, dmax) _strtouppercase_s_chk(dest, dmax, dest)
#define strzero_s(dest, dmax) _strzero_s_chk(dest, dmax, dest)
#define strcoll_s(dest, dmax, src, resultp) _strcoll_s_chk(dest, dmax, src, resultp, dest)
#define strset_s(dest, dmax, value) _strset_s_chk(dest, dmax, value, dest)
#define strnset_s(dest, dmax, value, n) _strnset_s_chk(dest, dmax, value, n, dest)
