typedef int errno_t;
#define RDK_SAFECLIB_ERR(rc)  printf("safeclib error at rc - %d %s %s:%d", rc,  __FILE__, __FUNCTION__, __LINE__)
#define EOK 0
#define ERR_CHK(rc)                                             \
    if(rc !=EOK) {                                              \
        RDK_SAFECLIB_ERR(rc);                                   \
    }

#define strncpy_s(dest, dmax, src, slen) _strncpy_s_chk(dest, dmax, src, slen, dest, src)
