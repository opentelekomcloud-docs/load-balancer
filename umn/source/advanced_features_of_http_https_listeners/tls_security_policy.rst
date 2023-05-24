:original_name: elb_ug_jt_0022.html

.. _elb_ug_jt_0022:

TLS Security Policy
===================

Scenarios
---------

When you add HTTPS listeners, you can select appropriate security policies to improve security. A security policy is a combination of TLS protocols of different versions and supported cipher suites.

-  Dedicated load balancers: You can select the default security policy or create a custom policy. For details, see :ref:`Creating a Custom Security Policy <elb_ug_jt_0022__section9832162313111>`.
-  Shared load balancers: You can select the default security policy.

Adding a Security Policy
------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Under **Listeners**, click **Add Listener**.

#. In the **Add Listener** dialog box, set **Frontend Protocol** to **HTTPS**.

#. In the **Add Listener** dialog box, expand **Advanced Settings** and select a security policy. You can select a default or custom security policy. If no custom security policies are available in the list, you can :ref:`create a security group <elb_ug_jt_0022__section9832162313111>`. :ref:`Table 1 <elb_ug_jt_0022__table1247813103533>` lists the default security policies.

   .. _elb_ug_jt_0022__table1247813103533:

   .. table:: **Table 1** Default security policies

      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | Security Policy                                    | Description                                                                                                           | TLS Versions    | Cipher Suites                    |
      +====================================================+=======================================================================================================================+=================+==================================+
      | TLS-1-0                                            | TLS 1.0, TLS 1.1, and TLS 1.2 and supported cipher suites (high compatibility and moderate security)                  | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       | TLS 1.1         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       | TLS 1.0         | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                                       |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA        |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA        |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA                    |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA                    |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-1                                            | TLS 1.1 and TLS 1.2 and supported cipher suites (moderate compatibility and moderate security)                        | TLS 1.2         |                                  |
      |                                                    |                                                                                                                       |                 |                                  |
      |                                                    |                                                                                                                       | TLS 1.1         |                                  |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2                                            | TLS 1.2 and supported cipher suites (moderate compatibility and high security)                                        | TLS 1.2         |                                  |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-0-Inherit                                    | TLS 1.0, TLS 1.1, and TLS 1.2 and supported cipher suites (high compatibility and moderate security)                  | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       | TLS 1.1         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       | TLS 1.0         | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                                       |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA        |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA          |
      |                                                    |                                                                                                                       |                 | -  DHE-RSA-AES128-SHA            |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA        |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA                    |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA                    |
      |                                                    |                                                                                                                       |                 | -  DHE-DSS-AES128-SHA            |
      |                                                    |                                                                                                                       |                 | -  CAMELLIA128-SHA               |
      |                                                    |                                                                                                                       |                 | -  EDH-RSA-DES-CBC3-SHA          |
      |                                                    |                                                                                                                       |                 | -  DES-CBC3-SHA                  |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-RC4-SHA             |
      |                                                    |                                                                                                                       |                 | -  RC4-SHA                       |
      |                                                    |                                                                                                                       |                 | -  DHE-RSA-AES256-SHA            |
      |                                                    |                                                                                                                       |                 | -  DHE-DSS-AES256-SHA            |
      |                                                    |                                                                                                                       |                 | -  DHE-RSA-CAMELLIA256-SHA       |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2-Strict                                     | Strict TLS 1.2 and supported cipher suites (low compatibility and ultra-high security)                                | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       |                 | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                                       |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-0-WITH-1-3 (for dedicated load balancers)    | TLS 1.0 and later, and supported cipher suites (ultra-high compatibility and low security)                            | TLS 1.3         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       | TLS 1.2         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       | TLS 1.1         | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                                       |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                                       | TLS 1.0         | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA        |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA        |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA                    |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA                    |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_128_GCM_SHA256        |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_256_GCM_SHA384        |
      |                                                    |                                                                                                                       |                 | -  TLS_CHACHA20_POLY1305_SHA256  |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_128_CCM_SHA256        |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_128_CCM_8_SHA256      |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2-FS-WITH-1-3 (for dedicated load balancers) | TLS 1.2 and later, and supported forward secrecy cipher suites (high compatibility and ultra-high security)           | TLS 1.3         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       | TLS 1.2         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_128_GCM_SHA256        |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_256_GCM_SHA384        |
      |                                                    |                                                                                                                       |                 | -  TLS_CHACHA20_POLY1305_SHA256  |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_128_CCM_SHA256        |
      |                                                    |                                                                                                                       |                 | -  TLS_AES_128_CCM_8_SHA256      |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2-FS                                         | TLS 1.2 and supported forward secrecy cipher suites (moderate compatibility and ultra-high security)                  | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | hybrid-policy-1-0 (dedicated load balancers)       | TLS 1.1 and TLS 1.2 and supported cipher suites (moderate compatibility and moderate security)                        | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                                       | TLS 1.1         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       |                 | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                                       |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-SHA        |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-SHA          |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES256-SHA        |
      |                                                    |                                                                                                                       |                 | -  AES128-SHA                    |
      |                                                    |                                                                                                                       |                 | -  AES256-SHA                    |
      |                                                    |                                                                                                                       |                 | -  ECC-SM4-SM3                   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-SM4-SM3                 |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | tls-1-2-strict-no-cbc (dedicated load balancers)   | TLS 1.2 and supported cipher suites that exclude CBC encryption algorithm (low compatibility and ultra-high security) | TLS 1.2         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                                       |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      +----------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+

   .. note::

      -  TLS-1-0-WITH-1-3, TLS-1-2-FS-WITH-1-3, TLS-1-2-FS, hybrid-policy-1-0, and tls-1-2-strict-no-cbc are available only for dedicated load balancers.
      -  The latest TLS version supported by dedicated load balancers is TLS 1.3, while the latest version supported by shared load balancers is TLS 1.2.
      -  This table lists the cipher suites supported by ELB. Generally, clients also support multiple cipher suites. In actual use, the intersection of the cipher suites supported by ELB and those supported by clients is used, and the cipher suites supported by ELB take precedence.

#. Click **OK**.

Differences Between Security Policies
-------------------------------------

.. _elb_ug_jt_0022__table176661610814:

.. table:: **Table 2** Differences between the security policies

   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | Security Policy               | TLS-1-0 | TLS-1-1 | TLS-1-2 | TLS-1-0-Inherit | TLS-1-2-Strict | TLS-1-0-WITH-1-3 | TLS-1-2-FS-WITH-1-3 | TLS-1-2-FS | Hybrid-Policy-1-0 |
   +===============================+=========+=========+=========+=================+================+==================+=====================+============+===================+
   | TLS versions                  |         |         |         |                 |                |                  |                     |            |                   |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS 1.3                       | ``-``   | ``-``   | ``-``   | ``-``           | ``-``          | Y                | Y                   | Y          | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS 1.2                       | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS 1.1                       | Y       | Y       | ``-``   | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS 1.0                       | Y       | ``-``   | ``-``   | Y               | ``-``          | Y                | ``-``               | ``-``      | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | Cipher suite                  |         |         |         |                 |                |                  |                     |            |                   |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | EDHE-RSA-AES128-GCM-SHA256    | Y       | Y       | Y       | ``-``           | Y              | ``-``            | ``-``               | ``-``      | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-RSA-AES256-GCM-SHA384   | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-RSA-AES128-SHA256       | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-RSA-AES256-SHA384       | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | AES128-GCM-SHA256             | Y       | Y       | Y       | Y               | Y              | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | AES256-GCM-SHA384             | Y       | Y       | Y       | Y               | Y              | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | AES128-SHA256                 | Y       | Y       | Y       | Y               | Y              | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | AES256-SHA256                 | Y       | Y       | Y       | Y               | Y              | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-RSA-AES128-SHA          | Y       | Y       | Y       | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-RSA-AES256-SHA          | Y       | Y       | Y       | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | AES128-SHA                    | Y       | Y       | Y       | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | AES256-SHA                    | Y       | Y       | Y       | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-ECDSA-AES128-GCM-SHA256 | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-ECDSA-AES128-SHA256     | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-ECDSA-AES128-SHA        | Y       | Y       | Y       | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-ECDSA-AES256-GCM-SHA384 | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-ECDSA-AES256-SHA384     | Y       | Y       | Y       | Y               | Y              | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-ECDSA-AES256-SHA        | Y       | Y       | Y       | Y               | ``-``          | Y                | ``-``               | ``-``      | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | ECDHE-RSA-AES128-GCM-SHA256   | ``-``   | ``-``   | ``-``   | Y               | ``-``          | Y                | Y                   | Y          | Y                 |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS_AES_256_GCM_SHA384        | ``-``   | ``-``   | ``-``   | ``-``           | ``-``          | Y                | Y                   | Y          | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS_CHACHA20_POLY1305_SHA256  | ``-``   | ``-``   | ``-``   | ``-``           | ``-``          | Y                | Y                   | Y          | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS_AES_128_GCM_SHA256        | ``-``   | ``-``   | ``-``   | ``-``           | ``-``          | Y                | Y                   | Y          | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS_AES_128_CCM_8_SHA256      | ``-``   | ``-``   | ``-``   | ``-``           | ``-``          | Y                | Y                   | Y          | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+
   | TLS_AES_128_CCM_SHA256        | ``-``   | ``-``   | ``-``   | ``-``           | ``-``          | Y                | Y                   | Y          | ``-``             |
   +-------------------------------+---------+---------+---------+-----------------+----------------+------------------+---------------------+------------+-------------------+

.. _elb_ug_jt_0022__section9832162313111:

Creating a Custom Security Policy
---------------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image3| and select the desired region and project.

#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **TLS Security Policies**.

#. On the displayed page, click **Create Custom Security Policy** in the upper right corner.

#. Configure the parameters based on :ref:`Table 3 <elb_ug_jt_0022__table3263104318541>`.

   .. _elb_ug_jt_0022__table3263104318541:

   .. table:: **Table 3** Custom security policy parameters

      +-----------------------+------------------------------------------------------------------------------------------------------+-----------------------+
      | Parameter             | Description                                                                                          | Example Value         |
      +=======================+======================================================================================================+=======================+
      | Name                  | Specifies the name of the custom security policy.                                                    | tls-test              |
      +-----------------------+------------------------------------------------------------------------------------------------------+-----------------------+
      | TLS Version           | Specifies the TLS version supported by the custom security policy. You can select multiple versions: | ``-``                 |
      |                       |                                                                                                      |                       |
      |                       | -  TLS 1.0                                                                                           |                       |
      |                       | -  TLS 1.1                                                                                           |                       |
      |                       | -  TLS 1.2                                                                                           |                       |
      |                       | -  TLS 1.3                                                                                           |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------+-----------------------+
      | Cipher Suite          | Specifies the cipher suites that match the selected TLS versions.                                    | ``-``                 |
      +-----------------------+------------------------------------------------------------------------------------------------------+-----------------------+
      | Description           | Provides supplementary information about the custom security policy.                                 | ``-``                 |
      +-----------------------+------------------------------------------------------------------------------------------------------+-----------------------+

#. Click **OK**.

Modifying a Custom Security Policy
----------------------------------

You can modify a custom security policy as you need.

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **TLS Security Policies**.
#. On the **TLS Security Policies** page, click **Custom Security Policies**, locate the custom security policy, and click **Modify** in the **Operation** column.
#. In displayed dialog box, modify the custom security policy as described in :ref:`Table 3 <elb_ug_jt_0022__table3263104318541>`.
#. Click **OK**.

Deleting a Custom Security Policy
---------------------------------

You can delete a custom security policy as you need.

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **TLS Security Policies**.
#. On the **TLS Security Policies** page, click **Custom Security Policies**, locate the custom security policy, and click **Delete** in the **Operation** column.
#. Click **Yes**.

Changing a Security Policy
--------------------------

When you change a security policy, ensure that the security group containing backend servers allows traffic from 100.125.0.0/16 to backend servers and allows ICMP packets for UDP health checks. Otherwise, backend servers will be considered unhealthy, and routing will be affected.

#. Log in to the management console.
#. In the upper left corner of the page, click |image9| and select the desired region and project.
#. Hover on |image10| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. On the **Listeners** tab page, locate the listener, click |image11| next to the listener name, and select **Modify Listener**.
#. In the **Modify Listener** dialog box, expand **Advanced Settings** and change the security policy.
#. Click **Next**.
#. Click **Finish**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001417088430.png
.. |image5| image:: /_static/images/en-us_image_0000001211126503.png
.. |image6| image:: /_static/images/en-us_image_0000001417088430.png
.. |image7| image:: /_static/images/en-us_image_0000001211126503.png
.. |image8| image:: /_static/images/en-us_image_0000001417088430.png
.. |image9| image:: /_static/images/en-us_image_0000001211126503.png
.. |image10| image:: /_static/images/en-us_image_0000001417088430.png
.. |image11| image:: /_static/images/en-us_image_0000001501069089.png
