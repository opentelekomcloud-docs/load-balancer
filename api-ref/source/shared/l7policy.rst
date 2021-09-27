=================
Forwarding Policy
=================

Adding a Forwarding Policy
==========================

Function
^^^^^^^^

This API is used to add a forwarding policy. The listener and forwarding policy
determine how traffic is forwarded to backend servers.

-  By matching the URL or domain name specified in the forwarding policy when
   **action** is set to **REDIRECT_TO_POOL**, the load balancer distributes the
   traffic to backend servers in a specific backend server group.  -  When
   **action** is set to **REDIRECT_TO_LISTENER**, the HTTP listener is
   redirected to an HTTPS listener, and requests are routed by the HTTPS
   listener.

Constraints
^^^^^^^^^^^

Currently, only redirects from an HTTP listener to an HTTPS listener are
supported. When **action** is set to **REDIRECT_TO_LISTENER**, the listener
specified by **listener_id** can only be an HTTP listener, and the listener
specified by **redirect_listener_id** can only be an HTTPS listener.

The load balancer of the HTTPS listener to which traffic is redirected must be
the same as that of the HTTP listener.

URI
^^^

POST /v2.0/lbaas/l7policies

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                        |
   +===========+===========+========+====================================================================+
   | l7policy  | Yes       | Object | Specifies the forwarding policy. For details, see :ref:`sl7pc_t2`. |
   +-----------+-----------+--------+--------------------------------------------------------------------+

.. _sl7pc_t2:
.. table:: **Table 2** **l7policy** parameter description

   +----------------------+-----------+---------+-----------------------------------+
   | Parameter            | Mandatory | Type    | Description                       |
   +======================+===========+=========+===================================+
   | tenant_id            | No        | String  | Specifies the ID of the           |
   |                      |           |         | project where the                 |
   |                      |           |         | forwarding policy is used.        |
   |                      |           |         |                                   |
   |                      |           |         | The value must be the same        |
   |                      |           |         | as the value of                   |
   |                      |           |         | **tenant_id** in the token.       |
   |                      |           |         |                                   |
   |                      |           |         | The value contains a              |
   |                      |           |         | maximum of 255 characters.        |
   +----------------------+-----------+---------+-----------------------------------+
   | name                 | No        | String  | Specifies the forwarding          |
   |                      |           |         | policy name.                      |
   |                      |           |         |                                   |
   |                      |           |         | The value contains a              |
   |                      |           |         | maximum of 255 characters.        |
   +----------------------+-----------+---------+-----------------------------------+
   | admin_state_up       | No        | Boolean | Specifies the                     |
   |                      |           |         | administrative status of          |
   |                      |           |         | the forwarding policy.            |
   |                      |           |         |                                   |
   |                      |           |         | This parameter is reserved,       |
   |                      |           |         | and the default value is          |
   |                      |           |         | **true**.                         |
   +----------------------+-----------+---------+-----------------------------------+
   | description          | No        | String  | Provides supplementary            |
   |                      |           |         | information about the             |
   |                      |           |         | forwarding policy.                |
   |                      |           |         |                                   |
   |                      |           |         | The value contains a              |
   |                      |           |         | maximum of 255 characters.        |
   +----------------------+-----------+---------+-----------------------------------+
   | listener_id          | Yes       | String  | Specifies the ID of the           |
   |                      |           |         | listener to which the             |
   |                      |           |         | forwarding policy is added.       |
   |                      |           |         |                                   |
   |                      |           |         | -  When **action** is set         |
   |                      |           |         |    to **REDIRECT_TO_POOL**,       |
   |                      |           |         |    forwarding policies can        |
   |                      |           |         |    be added to a listener         |
   |                      |           |         |    with **protocol** set to       |
   |                      |           |         |    **HTTP** or                    |
   |                      |           |         |    **TERMINATED_HTTPS**.          |
   |                      |           |         | -  When **action** is set         |
   |                      |           |         |    to                             |
   |                      |           |         |                                   |
   |                      |           |         |   **REDIRECT_TO_LISTENER**,       |
   |                      |           |         |    forwarding policies can        |
   |                      |           |         |    be added to a listener         |
   |                      |           |         |    with **protocol** set to       |
   |                      |           |         |    **HTTP**.                      |
   +----------------------+-----------+---------+-----------------------------------+
   | action               | Yes       | String  | Specifies whether requests        |
   |                      |           |         | are forwarded to another          |
   |                      |           |         | backend server group or           |
   |                      |           |         | redirected to an HTTPS            |
   |                      |           |         | listener.                         |
   |                      |           |         |                                   |
   |                      |           |         | The value can be one of the       |
   |                      |           |         | following:                        |
   |                      |           |         |                                   |
   |                      |           |         | -  **REDIRECT_TO_POOL**:          |
   |                      |           |         |    Requests are forwarded         |
   |                      |           |         |    to the backend server          |
   |                      |           |         |    group specified by             |
   |                      |           |         |    **redirect_pool_id**.          |
   |                      |           |         | -                                 |
   |                      |           |         |   **REDIRECT_TO_LISTENER**:       |
   |                      |           |         |    Requests are redirected        |
   |                      |           |         |    from the HTTP listener         |
   |                      |           |         |    specified by                   |
   |                      |           |         |    **listener_id** to the         |
   |                      |           |         |    HTTPS listener specified       |
   |                      |           |         |    by                             |
   |                      |           |         |                                   |
   |                      |           |         |   **redirect_listener_id**.       |
   +----------------------+-----------+---------+-----------------------------------+
   | redirect_pool_id     | No        | String  | Specifies the ID of the           |
   |                      |           |         | backend server group to           |
   |                      |           |         | which traffic is forwarded.       |
   |                      |           |         | The default value is              |
   |                      |           |         | **null**.                         |
   |                      |           |         |                                   |
   |                      |           |         | This parameter is mandatory       |
   |                      |           |         | when **action** is set to         |
   |                      |           |         | **REDIRECT_TO_POOL**.             |
   |                      |           |         |                                   |
   |                      |           |         | This parameter cannot be          |
   |                      |           |         | specified when **action**         |
   |                      |           |         | is set to                         |
   |                      |           |         | **REDIRECT_TO_LISTENER**.         |
   |                      |           |         |                                   |
   |                      |           |         | The backend server group          |
   |                      |           |         | must meet the following           |
   |                      |           |         | requirements:                     |
   |                      |           |         |                                   |
   |                      |           |         | -  Cannot be the default          |
   |                      |           |         |    backend server group of        |
   |                      |           |         |    the listener.                  |
   |                      |           |         | -  Cannot be the backend          |
   |                      |           |         |    server group used by           |
   |                      |           |         |    forwarding policies of         |
   |                      |           |         |    other listeners.               |
   +----------------------+-----------+---------+-----------------------------------+
   | redirect_listener_id | No        | String  | Specifies the ID of the           |
   |                      |           |         | listener to which the             |
   |                      |           |         | traffic is redirected. The        |
   |                      |           |         | default value is **null**.        |
   |                      |           |         |                                   |
   |                      |           |         | This parameter cannot be          |
   |                      |           |         | specified when **action**         |
   |                      |           |         | is set to                         |
   |                      |           |         | **REDIRECT_TO_POOL**.             |
   |                      |           |         |                                   |
   |                      |           |         | This parameter is mandatory       |
   |                      |           |         | when **action** is set to         |
   |                      |           |         | **REDIRECT_TO_LISTENER**,         |
   |                      |           |         | and the listener must meet        |
   |                      |           |         | the following requirements:       |
   |                      |           |         |                                   |
   |                      |           |         | -  Can only be an HTTPS           |
   |                      |           |         |    listener.                      |
   |                      |           |         | -  Can only be a listener         |
   |                      |           |         |    of the same load               |
   |                      |           |         |    balancer.                      |
   +----------------------+-----------+---------+-----------------------------------+
   | redirect_url         | No        | String  | Specifies the URL to which        |
   |                      |           |         | traffic is redirected. The        |
   |                      |           |         | default value is **null**.        |
   |                      |           |         |                                   |
   |                      |           |         | This parameter is reserved.       |
   |                      |           |         |                                   |
   |                      |           |         | The value contains a              |
   |                      |           |         | maximum of 255 characters.        |
   +----------------------+-----------+---------+-----------------------------------+
   | position             | No        | Integer | Specifies the forwarding          |
   |                      |           |         | priority. The value ranges        |
   |                      |           |         | from **1** to **100**. The        |
   |                      |           |         | default value is **100**.         |
   |                      |           |         |                                   |
   |                      |           |         | This parameter is reserved.       |
   +----------------------+-----------+---------+-----------------------------------+
   | rules                | No        | Array   | Lists the forwarding rules        |
   |                      |           |         | of the forwarding policy.         |
   |                      |           |         | For details, see :ref:`sl7pc_t3`. |
   |                      |           |         |                                   |
   |                      |           |         | The list contains a maximum       |
   |                      |           |         | of two rules, and the             |
   |                      |           |         | **type** parameter of each        |
   |                      |           |         | rule must be unique.              |
   +----------------------+-----------+---------+-----------------------------------+

.. _sl7pc_t3:
.. table:: **Table 3** **rules** parameter description

   +----------------+---------------+----------+--------------------------------------+
   | **Parameter**  | **Mandatory** | **Type** | **Description**                      |
   +================+===============+==========+======================================+
   | admin_state_up | No            | Boolean  | Specifies the                        |
   |                |               |          | administrative status of             |
   |                |               |          | the forwarding rule.                 |
   |                |               |          |                                      |
   |                |               |          | This parameter is reserved,          |
   |                |               |          | and the default value is             |
   |                |               |          | **true**.                            |
   +----------------+---------------+----------+--------------------------------------+
   | type           | Yes           | String   | Specifies the match type of          |
   |                |               |          | a forwarding rule.                   |
   |                |               |          |                                      |
   |                |               |          | The value range varies               |
   |                |               |          | depending on the protocol            |
   |                |               |          | of the backend server                |
   |                |               |          | group:                               |
   |                |               |          |                                      |
   |                |               |          | -  **HOST_NAME**: matches            |
   |                |               |          |    the domain name in the            |
   |                |               |          |    request.                          |
   |                |               |          | -  **PATH**: matches the             |
   |                |               |          |    path in the request.              |
   |                |               |          |                                      |
   |                |               |          | The match type of                    |
   |                |               |          | forwarding rules in a                |
   |                |               |          | forwarding policy must be            |
   |                |               |          | unique.                              |
   +----------------+---------------+----------+--------------------------------------+
   | compare_type   | Yes           | String   | Specifies the match mode.            |
   |                |               |          | The options are as follows:          |
   |                |               |          |                                      |
   |                |               |          | When **type** is set to              |
   |                |               |          | **HOST_NAME**, the value of          |
   |                |               |          | this parameter can only be           |
   |                |               |          | the following:                       |
   |                |               |          |                                      |
   |                |               |          | -  **EQUAL_TO**: indicates           |
   |                |               |          |    exact match.                      |
   |                |               |          |                                      |
   |                |               |          | When **type** is set to              |
   |                |               |          | **PATH**, the value of this          |
   |                |               |          | parameter can be one of the          |
   |                |               |          | following:                           |
   |                |               |          |                                      |
   |                |               |          | -  **REGEX**: indicates              |
   |                |               |          |    regular expression                |
   |                |               |          |    match.                            |
   |                |               |          | -  **STARTS_WITH**:                  |
   |                |               |          |    indicates prefix match.           |
   |                |               |          | -  **EQUAL_TO**: indicates           |
   |                |               |          |    exact match.                      |
   +----------------+---------------+----------+--------------------------------------+
   | invert         | No            | Boolean  | Specifies whether reverse            |
   |                |               |          | matching is supported.               |
   |                |               |          |                                      |
   |                |               |          | The value can be **true**            |
   |                |               |          | or **false**. The default            |
   |                |               |          | value is **false**.                  |
   |                |               |          |                                      |
   |                |               |          | This parameter is reserved.          |
   +----------------+---------------+----------+--------------------------------------+
   | key            | No            | String   | Specifies the key of the             |
   |                |               |          | match content. The default           |
   |                |               |          | value is **null**.                   |
   |                |               |          |                                      |
   |                |               |          | This parameter is reserved.          |
   +----------------+---------------+----------+--------------------------------------+
   | value          | Yes           | String   | Specifies the value of the           |
   |                |               |          | match content. The value             |
   |                |               |          | cannot contain spaces.               |
   |                |               |          |                                      |
   |                |               |          | - When **type** is set to            |
   |                |               |          |   **HOST_NAME**, the value           |
   |                |               |          |   can contain a maximum of           |
   |                |               |          |   100 characters that                |
   |                |               |          |   contain only letters,              |
   |                |               |          |   digits, hyphens (-), and           |
   |                |               |          |   periods (.), and must              |
   |                |               |          |   start with a letter or             |
   |                |               |          |   digit.                             |
   |                |               |          | - When **type** is set to            |
   |                |               |          |   **PATH**, the value can            |
   |                |               |          |   contain a maximum of 128           |
   |                |               |          |   characters. When                   |
   |                |               |          |   **compare_type** is set            |
   |                |               |          |   to **STARTS_WITH** or              |
   |                |               |          |   **EQUAL_TO**, the value            |
   |                |               |          |   must start with a slash            |
   |                |               |          |   (/) and can contain only           |
   |                |               |          |   letters, digits, and               |
   |                |               |          |   special characters                 |
   |                |               |          |   \_~';@^-%#&$.*+?,=!:&vert;\/()[]{} |
   +----------------+---------------+----------+--------------------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+--------+--------------------------------------------------------------------+
   | Parameter | Type   | Description                                                        |
   +===========+========+====================================================================+
   | l7policy  | Object | Specifies the forwarding policy. For details, see :ref:`sl7pc_t5`. |
   +-----------+--------+--------------------------------------------------------------------+

.. _sl7pc_t5:
.. table:: **Table 5** **l7policy** parameter description

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | id                   | String  | Specifies the forwarding policy ID.   |
   +----------------------+---------+---------------------------------------+
   | tenant_id            | String  | Specifies the ID of the project where |
   |                      |         | the forwarding policy is used.        |
   +----------------------+---------+---------------------------------------+
   | name                 | String  | Specifies the forwarding policy name. |
   +----------------------+---------+---------------------------------------+
   | admin_state_up       | Boolean | Specifies the administrative status   |
   |                      |         | of the forwarding policy.             |
   |                      |         |                                       |
   |                      |         | This parameter is reserved. The value |
   |                      |         | can be **true** or **false**.         |
   |                      |         |                                       |
   |                      |         | -  **true**: Enabled                  |
   |                      |         | -  **false**: Disabled                |
   +----------------------+---------+---------------------------------------+
   | description          | String  | Provides supplementary information    |
   |                      |         | about the forwarding policy.          |
   +----------------------+---------+---------------------------------------+
   | listener_id          | String  | Specifies the ID of the listener to   |
   |                      |         | which the forwarding policy is added. |
   +----------------------+---------+---------------------------------------+
   | action               | String  | Specifies whether requests are        |
   |                      |         | forwarded to another backend server   |
   |                      |         | group or redirected to an HTTPS       |
   |                      |         | listener.                             |
   |                      |         |                                       |
   |                      |         | The value can be one of the           |
   |                      |         | following:                            |
   |                      |         |                                       |
   |                      |         | -  **REDIRECT_TO_POOL**: Requests are |
   |                      |         |    forwarded to the backend server    |
   |                      |         |    group specified by                 |
   |                      |         |    **redirect_pool_id**.              |
   |                      |         | -  **REDIRECT_TO_LISTENER**: Requests |
   |                      |         |    are redirected from the HTTP       |
   |                      |         |    listener specified by              |
   |                      |         |    **listener_id** to the HTTPS       |
   |                      |         |    listener specified by              |
   |                      |         |    **redirect_listener_id**.          |
   +----------------------+---------+---------------------------------------+
   | redirect_pool_id     | String  | Specifies the ID of the backend       |
   |                      |         | server group to which traffic is      |
   |                      |         | forwarded.                            |
   +----------------------+---------+---------------------------------------+
   | redirect_listener_id | String  | Specifies the ID of the listener to   |
   |                      |         | which the traffic is redirected.      |
   +----------------------+---------+---------------------------------------+
   | redirect_url         | String  | Specifies the URL to which traffic is |
   |                      |         | redirected.                           |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | rules                | Array   | Lists the forwarding rules of the     |
   |                      |         | forwarding policy. For details, see   |
   |                      |         | :ref:`sl7pc_t6`.                      |
   +----------------------+---------+---------------------------------------+
   | position             | Integer | Specifies the forwarding priority.    |
   |                      |         | The value ranges from **1** to        |
   |                      |         | **100**. The default value is         |
   |                      |         | **100**.                              |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | provisioning_status  | String  | This parameter is reserved, and its   |
   |                      |         | value can only be **ACTIVE**.         |
   |                      |         |                                       |
   |                      |         | It specifies the provisioning status  |
   |                      |         | of the forwarding policy.             |
   +----------------------+---------+---------------------------------------+

.. _sl7pc_t6:
.. table:: **Table 6** **rules** parameter description

   ========= ====== ===============================================================
   Parameter Type   Description
   ========= ====== ===============================================================
   id        String Lists the IDs of the forwarding rules in the forwarding policy.
   ========= ====== ===============================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Adding a forwarding policy

   .. code::

      POST https://{Endpoint}/v2.0/lbaas/l7policies

      {
          "l7policy": {
              "name": "niubiao_yaqing_api-2",
              "listener_id": "3e24a3ca-11e5-4aa3-abd4-61ba0a8a18f1",
              "action": "REDIRECT_TO_POOL",
              "redirect_pool_id": "6460f13a-76de-43c7-b776-4fefc06a676e",
              "rules": [
                  {
                      "type": "PATH",
                      "compare_type": "EQUAL_TO",
                      "value": "/test"
                  },
                  {
                      "type": "HOST_NAME",
                      "compare_type": "EQUAL_TO",
                      "value": "www.test.com"
                  }
              ]
          }
      }

-  Example request 2: Creating a redirect

   .. code::

      POST https://{Endpoint}/v2.0/lbaas/l7policies

      {
          "l7policy": {
              "action": "REDIRECT_TO_LISTENER",
              "listener_id": "4ef8553e-9ef7-4859-a42d-919feaf89d60",
              "redirect_listener_id": "3ee10199-a7b4-4784-93cd-857afe9d0890",
              "name": "redirect-test"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "l7policy": {
              "redirect_pool_id": "6460f13a-76de-43c7-b776-4fefc06a676e",
              "description": "",
              "admin_state_up": true,
              "rules": [
                  {
                      "id": "742600d9-2a14-4808-af69-336883dbb590"
                  },
                  {
                      "id": "3251ed77-0d52-412b-9310-733636bb3fbf"
                  }
              ],
              "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
              "listener_id": "3e24a3ca-11e5-4aa3-abd4-61ba0a8a18f1",
              "redirect_url": null,
              "redirect_listener_id": null,
              "action": "REDIRECT_TO_POOL",
              "position": 100,
              "provisioning_status": "ACTIVE",

              "id": "65d6e115-f179-4bcd-9bbb-1484e5f8ee81",
              "name": "niubiao_yaqing-_api-2"
          }
      }

-  Example response 2

   .. code::

      {
          "l7policy": {
              "redirect_pool_id": null,
              "description": "",
              "admin_state_up": true,
              "rules": [ ],
              "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
              "listener_id": "4ef8553e-9ef7-4859-a42d-919feaf89d60",
              "redirect_url": null,
              "redirect_listener_id": "3ee10199-a7b4-4784-93cd-857afe9d0890",
              "action": "REDIRECT_TO_LISTENER",
              "position": 100,
              "provisioning_status": "ACTIVE",
              "id": "bc4e4338-480f-4a98-8245-5bb1964f0e1d",
              "name": "redirect-test"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Forwarding Policies
============================

Function
^^^^^^^^

This API is used to query the forwarding policies. Filter query and pagination
query are supported. Unless otherwise specified, exact match is applied.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query. Parameters **marker** and **page_reverse** take effect only when they
are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/l7policies

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +----------------------+---------------+---------+-----------------------------+
   | Parameter            | **Mandatory** | Type    | Description                 |
   +======================+===============+=========+=============================+
   | marker               | No            | String  | Specifies the ID of         |
   |                      |               |         | the forwarding policy       |
   |                      |               |         | from which pagination       |
   |                      |               |         | query starts, that          |
   |                      |               |         | is, the ID of the           |
   |                      |               |         | last forwarding             |
   |                      |               |         | policy on the               |
   |                      |               |         | previous page.              |
   |                      |               |         |                             |
   |                      |               |         | This parameter must         |
   |                      |               |         | be used together with       |
   |                      |               |         | **limit**.                  |
   +----------------------+---------------+---------+-----------------------------+
   | limit                | No            | Integer | Specifies the number        |
   |                      |               |         | of forwarding               |
   |                      |               |         | policies on each            |
   |                      |               |         | page. If this               |
   |                      |               |         | parameter is not set,       |
   |                      |               |         | all forwarding              |
   |                      |               |         | policies are queried        |
   |                      |               |         | by default.                 |
   +----------------------+---------------+---------+-----------------------------+
   | page_reverse         | No            | Boolean | Specifies the page          |
   |                      |               |         | direction. The value        |
   |                      |               |         | can be **true** or          |
   |                      |               |         | **false**, and the          |
   |                      |               |         | default value is            |
   |                      |               |         | **false**. The last         |
   |                      |               |         | page in the list            |
   |                      |               |         | requested with              |
   |                      |               |         | **page_reverse** set        |
   |                      |               |         | to **false** will not       |
   |                      |               |         | contain the "next"          |
   |                      |               |         | link, and the last          |
   |                      |               |         | page in the list            |
   |                      |               |         | requested with              |
   |                      |               |         | **page_reverse** set        |
   |                      |               |         | to **true** will not        |
   |                      |               |         | contain the                 |
   |                      |               |         | "previous" link.            |
   |                      |               |         |                             |
   |                      |               |         | This parameter must         |
   |                      |               |         | be used together with       |
   |                      |               |         | **limit**.                  |
   +----------------------+---------------+---------+-----------------------------+
   | id                   | No            | String  | Specifies the               |
   |                      |               |         | forwarding policy ID.       |
   +----------------------+---------------+---------+-----------------------------+
   | tenant_id            | No            | String  | Specifies the ID of         |
   |                      |               |         | the project where the       |
   |                      |               |         | forwarding policy is        |
   |                      |               |         | used.                       |
   |                      |               |         |                             |
   |                      |               |         | The value contains a        |
   |                      |               |         | maximum of 255              |
   |                      |               |         | characters.                 |
   +----------------------+---------------+---------+-----------------------------+
   | name                 | No            | String  | Specifies the               |
   |                      |               |         | forwarding policy           |
   |                      |               |         | name.                       |
   |                      |               |         |                             |
   |                      |               |         | The value contains a        |
   |                      |               |         | maximum of 255              |
   |                      |               |         | characters.                 |
   +----------------------+---------------+---------+-----------------------------+
   | admin_state_up       | No            | Boolean | Specifies the               |
   |                      |               |         | administrative status       |
   |                      |               |         | of the forwarding           |
   |                      |               |         | policy.                     |
   |                      |               |         |                             |
   |                      |               |         | This parameter is           |
   |                      |               |         | reserved, and the           |
   |                      |               |         | default value is            |
   |                      |               |         | **true**.                   |
   +----------------------+---------------+---------+-----------------------------+
   | description          | No            | String  | Provides                    |
   |                      |               |         | supplementary               |
   |                      |               |         | information about the       |
   |                      |               |         | forwarding policy.          |
   |                      |               |         |                             |
   |                      |               |         | The value contains a        |
   |                      |               |         | maximum of 255              |
   |                      |               |         | characters.                 |
   +----------------------+---------------+---------+-----------------------------+
   | listener_id          | No            | String  | Specifies the ID of         |
   |                      |               |         | the listener to which       |
   |                      |               |         | the forwarding policy       |
   |                      |               |         | is added.                   |
   +----------------------+---------------+---------+-----------------------------+
   | action               | No            | String  | Specifies whether           |
   |                      |               |         | requests are                |
   |                      |               |         | forwarded to another        |
   |                      |               |         | backend server group        |
   |                      |               |         | or redirected to an         |
   |                      |               |         | HTTPS listener.             |
   |                      |               |         |                             |
   |                      |               |         | The value can be one        |
   |                      |               |         | of the following:           |
   |                      |               |         |                             |
   |                      |               |         | - **REDIRECT_TO_POOL**:     |
   |                      |               |         |   Requests are              |
   |                      |               |         |   forwarded to the          |
   |                      |               |         |   backend server            |
   |                      |               |         |   group specified by        |
   |                      |               |         |   **redirect_pool_id**.     |
   |                      |               |         | - **REDIRECT_TO_LISTENER**: |
   |                      |               |         |   Requests are              |
   |                      |               |         |   redirected from           |
   |                      |               |         |   the HTTP listener         |
   |                      |               |         |   specified by              |
   |                      |               |         |   **listener_id** to        |
   |                      |               |         |   the HTTPS listener        |
   |                      |               |         |   specified by              |
   |                      |               |         |   **redirect_listener_id**. |
   +----------------------+---------------+---------+-----------------------------+
   | redirect_pool_id     | No            | String  | Specifies the ID of         |
   |                      |               |         | the backend server          |
   |                      |               |         | group to which              |
   |                      |               |         | traffic is forwarded.       |
   +----------------------+---------------+---------+-----------------------------+
   | redirect_listener_id | No            | String  | Specifies the ID of         |
   |                      |               |         | the listener to which       |
   |                      |               |         | the traffic is              |
   |                      |               |         | redirected.                 |
   +----------------------+---------------+---------+-----------------------------+
   | redirect_url         | No            | String  | Specifies the URL to        |
   |                      |               |         | which traffic is            |
   |                      |               |         | redirected.                 |
   |                      |               |         |                             |
   |                      |               |         | This parameter is           |
   |                      |               |         | reserved.                   |
   |                      |               |         |                             |
   |                      |               |         | The value contains a        |
   |                      |               |         | maximum of 255              |
   |                      |               |         | characters.                 |
   +----------------------+---------------+---------+-----------------------------+
   | position             | No            | Integer | Specifies the               |
   |                      |               |         | forwarding priority.        |
   |                      |               |         | The value ranges from       |
   |                      |               |         | **1** to **100**. The       |
   |                      |               |         | default value is            |
   |                      |               |         | **100**.                    |
   |                      |               |         |                             |
   |                      |               |         | This parameter is           |
   |                      |               |         | reserved.                   |
   +----------------------+---------------+---------+-----------------------------+
   | provisioning_status  | No            | String  | This parameter is           |
   |                      |               |         | reserved, and its           |
   |                      |               |         | value can only be           |
   |                      |               |         | **ACTIVE**.                 |
   |                      |               |         |                             |
   |                      |               |         | It specifies the            |
   |                      |               |         | provisioning status         |
   |                      |               |         | of the forwarding           |
   |                      |               |         | policy.                     |
   +----------------------+---------------+---------+-----------------------------+
   | display_all_rules    | No            | Boolean | Specifies whether to        |
   |                      |               |         | display all                 |
   |                      |               |         | forwarding rules            |
   |                      |               |         | added to the                |
   |                      |               |         | forwarding policy.          |
   |                      |               |         |                             |
   |                      |               |         | Value options:              |
   |                      |               |         |                             |
   |                      |               |         | **false**: Forwarding       |
   |                      |               |         | rules will not be           |
   |                      |               |         | displayed, and only         |
   |                      |               |         | IDs are displayed.          |
   |                      |               |         |                             |
   |                      |               |         | **true**: Forwarding        |
   |                      |               |         | rules will be               |
   |                      |               |         | displayed.                  |
   +----------------------+---------------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +------------------+-------+---------------------------------------+
   | Parameter        | Type  | Description                           |
   +==================+=======+=======================================+
   | l7policies       | Array | Lists the forwarding policies. For    |
   |                  |       | details, see :ref:`sl7pl_t3`.         |
   +------------------+-------+---------------------------------------+
   | l7policies_links | Array | Provides links to the previous or     |
   |                  |       | next page during pagination query,    |
   |                  |       | respectively.                         |
   |                  |       |                                       |
   |                  |       | This parameter exists only in the     |
   |                  |       | response body of pagination query.    |
   |                  |       |                                       |
   |                  |       | For details, see :ref:`sl7pl_t5`.     |
   +------------------+-------+---------------------------------------+

.. _sl7pl_t3:
.. table:: **Table 3** **l7policy** parameter description

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | id                   | String  | Specifies the forwarding policy ID.   |
   +----------------------+---------+---------------------------------------+
   | tenant_id            | String  | Specifies the ID of the project where |
   |                      |         | the forwarding policy is used.        |
   +----------------------+---------+---------------------------------------+
   | name                 | String  | Specifies the forwarding policy name. |
   +----------------------+---------+---------------------------------------+
   | admin_state_up       | Boolean | Specifies the administrative status   |
   |                      |         | of the forwarding policy.             |
   |                      |         |                                       |
   |                      |         | This parameter is reserved. The value |
   |                      |         | can be **true** or **false**.         |
   |                      |         |                                       |
   |                      |         | -  **true**: Enabled                  |
   |                      |         | -  **false**: Disabled                |
   +----------------------+---------+---------------------------------------+
   | description          | String  | Provides supplementary information    |
   |                      |         | about the forwarding policy.          |
   +----------------------+---------+---------------------------------------+
   | listener_id          | String  | Specifies the ID of the listener to   |
   |                      |         | which the forwarding policy is added. |
   +----------------------+---------+---------------------------------------+
   | action               | String  | Specifies whether requests are        |
   |                      |         | forwarded to another backend server   |
   |                      |         | group or redirected to an HTTPS       |
   |                      |         | listener.                             |
   |                      |         |                                       |
   |                      |         | The value can be one of the           |
   |                      |         | following:                            |
   |                      |         |                                       |
   |                      |         | -  **REDIRECT_TO_POOL**: Requests are |
   |                      |         |    forwarded to the backend server    |
   |                      |         |    group specified by                 |
   |                      |         |    **redirect_pool_id**.              |
   |                      |         | -  **REDIRECT_TO_LISTENER**: Requests |
   |                      |         |    are redirected from the HTTP       |
   |                      |         |    listener specified by              |
   |                      |         |    **listener_id** to the HTTPS       |
   |                      |         |    listener specified by              |
   |                      |         |    **redirect_listener_id**.          |
   +----------------------+---------+---------------------------------------+
   | redirect_pool_id     | String  | Specifies the ID of the backend       |
   |                      |         | server group to which traffic is      |
   |                      |         | forwarded.                            |
   +----------------------+---------+---------------------------------------+
   | redirect_listener_id | String  | Specifies the ID of the listener to   |
   |                      |         | which the traffic is redirected.      |
   +----------------------+---------+---------------------------------------+
   | redirect_url         | String  | Specifies the URL to which traffic is |
   |                      |         | redirected.                           |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | rules                | Array   | Lists the forwarding rules of the     |
   |                      |         | forwarding policy. For details, see   |
   |                      |         | :ref:`sl7pc_t6`.                      |
   +----------------------+---------+---------------------------------------+
   | position             | Integer | Specifies the forwarding priority.    |
   |                      |         | The value ranges from **1** to        |
   |                      |         | **100**. The default value is         |
   |                      |         | **100**.                              |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | provisioning_status  | String  | This parameter is reserved, and its   |
   |                      |         | value can only be **ACTIVE**.         |
   |                      |         |                                       |
   |                      |         | It specifies the provisioning status  |
   |                      |         | of the forwarding policy.             |
   +----------------------+---------+---------------------------------------+

.. _sl7pl_t4:
.. table:: **Table 4** **rules** parameter description

   ========= ====== ===============================================================
   Parameter Type   Description
   ========= ====== ===============================================================
   id        String Lists the IDs of the forwarding rules in the forwarding policy.
   ========= ====== ===============================================================

.. _sl7pl_t5:
.. table:: **Table 5** **l7policies_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page.                         |
   |           |        |                                       |
   |           |        | The value can be **next** or          |
   |           |        | **previous**. The value **next**      |
   |           |        | indicates the href containing the URL |
   |           |        | of the next page, and **previous**    |
   |           |        | indicates the href containing the URL |
   |           |        | of the previous page.                 |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all forwarding policies

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/l7policies

-  Example request 2: Querying forwarding policies through which requests are
   forwarded to the backend server group

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/l7policies?action=REDIRECT_TO_POOL

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "l7policies": [
              {
                  "redirect_pool_id": "431a03eb-81bb-408e-ae37-7ce19023692b",
                  "redirect_listener_id": null,
                  "description": "",
                  "admin_state_up": true,
                  "rules": [
                      {
                          "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
                      },
                      {
                          "id": "f02b3bca-69d2-4335-a3fa-a8054e996213"
                      }
                  ],
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

                  "listener_id": "26058b64-6185-4e06-874e-4bd68b7633d0",
                  "redirect_url": null,
                  "action": "REDIRECT_TO_POOL",
                  "position": 2,
                  "provisioning_status": "ACTIVE",
                  "id": "5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586",
                  "name": ""
              },
              {
                  "redirect_pool_id": "59eebd7b-c68f-4f8a-aa7f-e062e84c0690",
                  "redirect_listener_id": null,
                  "description": "",
                  "admin_state_up": true,
                  "rules": [
                      {
                          "id": "f4499f48-de3d-4efe-926d-926aa4d6aaf5"
                      }
                  ],
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",
                  "listener_id": "e1310063-00de-4867-ab55-ccac4d9db364",
                  "redirect_url": null,
                  "action": "REDIRECT_TO_POOL",
                  "position": 1,
                  "provisioning_status": "ACTIVE",
                  "id": "6cfd9d89-1d7e-4d84-ae1f-a8c5ff126f72",
                  "name": ""
              }
          ],
          "l7policies_links": [
              {
              "href": "https://{Endpoint}/v2.0/lbaas/l7policies/061f461c-c7cf-47ab-9583-09be5076cd09/rules?marker=167c1a31-bc12-4c3d-9ad1-c9bf450df4ce&page_reverse=True",
              "rel": "previous"
              }
          ]
      }

-  Example response 2

   .. code::

      {
          "l7policies": [
              {
                  "redirect_pool_id": "431a03eb-81bb-408e-ae37-7ce19023692b",
                  "redirect_listener_id": null,
                  "description": "",
                  "admin_state_up": true,
                  "rules": [
                      {
                          "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
                      },
                      {
                          "id": "f02b3bca-69d2-4335-a3fa-a8054e996213"
                      }
                  ],
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

                  "listener_id": "26058b64-6185-4e06-874e-4bd68b7633d0",
                  "redirect_url": null,
                  "action": "REDIRECT_TO_POOL",
                  "position": 2,
                  "provisioning_status": "ACTIVE",
                  "id": "5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586",
                  "name": ""
              },
              {
                  "redirect_pool_id": "59eebd7b-c68f-4f8a-aa7f-e062e84c0690",
                  "redirect_listener_id": null,
                  "description": "",
                  "admin_state_up": true,
                  "rules": [
                      {
                          "id": "f4499f48-de3d-4efe-926d-926aa4d6aaf5"
                      }
                  ],
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

                  "listener_id": "e1310063-00de-4867-ab55-ccac4d9db364",
                  "redirect_url": null,
                  "action": "REDIRECT_TO_POOL",
                  "position": 1,
                  "provisioning_status": "ACTIVE",
                  "id": "6cfd9d89-1d7e-4d84-ae1f-a8c5ff126f72",
                  "name": ""
              }
          ],
          "l7policies_links": [
              {
              "href": "https://{Endpoint}/v2.0/lbaas/l7policies/061f461c-c7cf-47ab-9583-09be5076cd09/rules?marker=167c1a31-bc12-4c3d-9ad1-c9bf450df4ce&page_reverse=True",
              "rel": "previous"
              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Forwarding Policy
=======================================

Function
^^^^^^^^

This API is used to query details about a forwarding policy.

URI
^^^

GET /v2.0/lbaas/l7policies/{l7policy_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+--------+---------------------------------------------------------------------+
   | Parameter | Type   | Description                                                         |
   +===========+========+=====================================================================+
   | l7policy  | Object | Specifies the forwarding policy. For details, see :ref:`sl7ps_t3`.  |
   +-----------+--------+---------------------------------------------------------------------+

.. _sl7ps_t3:
.. table:: **Table 3** **l7policy** parameter description

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | id                   | String  | Specifies the forwarding policy ID.   |
   +----------------------+---------+---------------------------------------+
   | tenant_id            | String  | Specifies the ID of the project where |
   |                      |         | the forwarding policy is used.        |
   +----------------------+---------+---------------------------------------+
   | name                 | String  | Specifies the forwarding policy name. |
   +----------------------+---------+---------------------------------------+
   | admin_state_up       | Boolean | Specifies the administrative status   |
   |                      |         | of the forwarding policy.             |
   |                      |         |                                       |
   |                      |         | This parameter is reserved. The value |
   |                      |         | can be **true** or **false**.         |
   |                      |         |                                       |
   |                      |         | -  **true**: Enabled                  |
   |                      |         | -  **false**: Disabled                |
   +----------------------+---------+---------------------------------------+
   | description          | String  | Provides supplementary information    |
   |                      |         | about the forwarding policy.          |
   +----------------------+---------+---------------------------------------+
   | listener_id          | String  | Specifies the ID of the listener to   |
   |                      |         | which the forwarding policy is added. |
   +----------------------+---------+---------------------------------------+
   | action               | String  | Specifies whether requests are        |
   |                      |         | forwarded to another backend server   |
   |                      |         | group or redirected to an HTTPS       |
   |                      |         | listener.                             |
   |                      |         |                                       |
   |                      |         | The value can be one of the           |
   |                      |         | following:                            |
   |                      |         |                                       |
   |                      |         | -  **REDIRECT_TO_POOL**: Requests are |
   |                      |         |    forwarded to the backend server    |
   |                      |         |    group specified by                 |
   |                      |         |    **redirect_pool_id**.              |
   |                      |         | -  **REDIRECT_TO_LISTENER**: Requests |
   |                      |         |    are redirected from the HTTP       |
   |                      |         |    listener specified by              |
   |                      |         |    **listener_id** to the HTTPS       |
   |                      |         |    listener specified by              |
   |                      |         |    **redirect_listener_id**.          |
   +----------------------+---------+---------------------------------------+
   | redirect_pool_id     | String  | Specifies the ID of the backend       |
   |                      |         | server group to which traffic is      |
   |                      |         | forwarded.                            |
   +----------------------+---------+---------------------------------------+
   | redirect_listener_id | String  | Specifies the ID of the listener to   |
   |                      |         | which the traffic is redirected.      |
   +----------------------+---------+---------------------------------------+
   | redirect_url         | String  | Specifies the URL to which traffic is |
   |                      |         | redirected.                           |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | rules                | Array   | Lists the forwarding rules of the     |
   |                      |         | forwarding policy. For details, see   |
   |                      |         | :ref:`sl7pc_t6`.                      |
   +----------------------+---------+---------------------------------------+
   | position             | Integer | Specifies the forwarding priority.    |
   |                      |         | The value ranges from **1** to        |
   |                      |         | **100**. The default value is         |
   |                      |         | **100**.                              |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | provisioning_status  | String  | This parameter is reserved, and its   |
   |                      |         | value can only be **ACTIVE**.         |
   |                      |         |                                       |
   |                      |         | It specifies the provisioning status  |
   |                      |         | of the forwarding policy.             |
   +----------------------+---------+---------------------------------------+

.. table:: **Table 4** **rules** parameter description

   ========= ====== ===============================================================
   Parameter Type   Description
   ========= ====== ===============================================================
   id        String Lists the IDs of the forwarding rules in the forwarding policy.
   ========= ====== ===============================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Querying details of a forwarding policy

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "l7policy": {
              "redirect_pool_id": "431a03eb-81bb-408e-ae37-7ce19023692b",
              "redirect_listener_id": null,
              "description": "",
              "admin_state_up": true,
              "rules": [
                  {
                      "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
                  },
                  {
                      "id": "f02b3bca-69d2-4335-a3fa-a8054e996213"
                  }
              ],
              "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",
              "listener_id": "26058b64-6185-4e06-874e-4bd68b7633d0",
              "redirect_url": null,
              "provisioning_status": "ACTIVE",
              "action": "REDIRECT_TO_POOL",
              "position": 1,
              "id": "5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586",
              "name": "l7policy-garry-1"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

.. _sl7pu:

Updating a Forwarding Policy
============================

Function
^^^^^^^^

This API is used to update a forwarding policy. You can select another backend
server group or redirect to another HTTPS listener.

URI
^^^

PUT /v2.0/lbaas/l7policies/{l7policy_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       Object Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                        |
   +===========+===========+========+====================================================================+
   | l7policy  | Yes       | Object | Specifies the forwarding policy. For details, see :ref:`sl7pu_t3`. |
   +-----------+-----------+--------+--------------------------------------------------------------------+

.. _sl7pu_t3:
.. table:: **Table 3** **l7policy** parameter description

   +----------------------+-----------+---------+-----------------------------+
   | Parameter            | Mandatory | Type    | Description                 |
   +======================+===========+=========+=============================+
   | name                 | No        | String  | Specifies the forwarding    |
   |                      |           |         | policy name.                |
   |                      |           |         |                             |
   |                      |           |         | The value contains a        |
   |                      |           |         | maximum of 255 characters.  |
   +----------------------+-----------+---------+-----------------------------+
   | description          | No        | String  | Provides supplementary      |
   |                      |           |         | information about the       |
   |                      |           |         | forwarding policy.          |
   |                      |           |         |                             |
   |                      |           |         | The value contains a        |
   |                      |           |         | maximum of 255 characters.  |
   +----------------------+-----------+---------+-----------------------------+
   | redirect_pool_id     | No        | String  | Specifies the ID of the     |
   |                      |           |         | backend server group to     |
   |                      |           |         | which traffic is forwarded. |
   |                      |           |         | The default value is        |
   |                      |           |         | **null**.                   |
   |                      |           |         |                             |
   |                      |           |         | This parameter is mandatory |
   |                      |           |         | when **action** is set to   |
   |                      |           |         | **REDIRECT_TO_POOL**.       |
   |                      |           |         |                             |
   |                      |           |         | This parameter cannot be    |
   |                      |           |         | specified when **action**   |
   |                      |           |         | is set to                   |
   |                      |           |         | **REDIRECT_TO_LISTENER**.   |
   |                      |           |         |                             |
   |                      |           |         | The backend server group    |
   |                      |           |         | must meet the following     |
   |                      |           |         | requirements:               |
   |                      |           |         |                             |
   |                      |           |         | -  Cannot be the default    |
   |                      |           |         |    backend server group of  |
   |                      |           |         |    the listener.            |
   |                      |           |         | -  Cannot be the backend    |
   |                      |           |         |    server group used by     |
   |                      |           |         |    forwarding policies of   |
   |                      |           |         |    other listeners.         |
   +----------------------+-----------+---------+-----------------------------+
   | redirect_listener_id | No        | String  | Specifies the ID of the     |
   |                      |           |         | listener to which the       |
   |                      |           |         | traffic is redirected. The  |
   |                      |           |         | default value is **null**.  |
   |                      |           |         |                             |
   |                      |           |         | This parameter is mandatory |
   |                      |           |         | when **action** is set to   |
   |                      |           |         | **REDIRECT_TO_LISTENER**.   |
   |                      |           |         |                             |
   |                      |           |         | This parameter cannot be    |
   |                      |           |         | specified when **action**   |
   |                      |           |         | is set to                   |
   |                      |           |         | **REDIRECT_TO_POOL**. The   |
   |                      |           |         | listener must meet the      |
   |                      |           |         | following requirements:     |
   |                      |           |         |                             |
   |                      |           |         | -  Can only be an HTTPS     |
   |                      |           |         |    listener.                |
   |                      |           |         | -  Can only be a listener   |
   |                      |           |         |    of the same load         |
   |                      |           |         |    balancer.                |
   +----------------------+-----------+---------+-----------------------------+
   | admin_state_up       | No        | Boolean | Specifies the               |
   |                      |           |         | administrative status of    |
   |                      |           |         | the forwarding policy.      |
   |                      |           |         |                             |
   |                      |           |         | This parameter is reserved, |
   |                      |           |         | and the default value is    |
   |                      |           |         | **true**.                   |
   +----------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+-----------+--------+---------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                         |
   +===========+===========+========+=====================================================================+
   | l7policy  | Yes       | Object | Specifies the forwarding policy. For details, see :ref:`sl7pu_t5`.  |
   +-----------+-----------+--------+---------------------------------------------------------------------+

.. _sl7pu_t5:
.. table:: **Table 5** **l7policy** parameter description

   +----------------------+---------+---------------------------------------+
   | Parameter            | Type    | Description                           |
   +======================+=========+=======================================+
   | id                   | String  | Specifies the forwarding policy ID.   |
   +----------------------+---------+---------------------------------------+
   | tenant_id            | String  | Specifies the ID of the project where |
   |                      |         | the forwarding policy is used.        |
   +----------------------+---------+---------------------------------------+
   | name                 | String  | Specifies the forwarding policy name. |
   +----------------------+---------+---------------------------------------+
   | admin_state_up       | Boolean | Specifies the administrative status   |
   |                      |         | of the forwarding policy.             |
   |                      |         |                                       |
   |                      |         | This parameter is reserved. The value |
   |                      |         | can be **true** or **false**.         |
   |                      |         |                                       |
   |                      |         | -  **true**: Enabled                  |
   |                      |         | -  **false**: Disabled                |
   +----------------------+---------+---------------------------------------+
   | description          | String  | Provides supplementary information    |
   |                      |         | about the forwarding policy.          |
   +----------------------+---------+---------------------------------------+
   | listener_id          | String  | Specifies the ID of the listener to   |
   |                      |         | which the forwarding policy is added. |
   +----------------------+---------+---------------------------------------+
   | action               | String  | Specifies whether requests are        |
   |                      |         | forwarded to another backend server   |
   |                      |         | group or redirected to an HTTPS       |
   |                      |         | listener.                             |
   |                      |         |                                       |
   |                      |         | The value can be one of the           |
   |                      |         | following:                            |
   |                      |         |                                       |
   |                      |         | -  **REDIRECT_TO_POOL**: Requests are |
   |                      |         |    forwarded to the backend server    |
   |                      |         |    group specified by                 |
   |                      |         |    **redirect_pool_id**.              |
   |                      |         | -  **REDIRECT_TO_LISTENER**: Requests |
   |                      |         |    are redirected from the HTTP       |
   |                      |         |    listener specified by              |
   |                      |         |    **listener_id** to the HTTPS       |
   |                      |         |    listener specified by              |
   |                      |         |    **redirect_listener_id**.          |
   +----------------------+---------+---------------------------------------+
   | redirect_pool_id     | String  | Specifies the ID of the backend       |
   |                      |         | server group to which traffic is      |
   |                      |         | forwarded.                            |
   +----------------------+---------+---------------------------------------+
   | redirect_listener_id | String  | Specifies the ID of the listener to   |
   |                      |         | which the traffic is redirected.      |
   +----------------------+---------+---------------------------------------+
   | redirect_url         | String  | Specifies the URL to which traffic is |
   |                      |         | redirected.                           |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | rules                | Array   | Lists the forwarding rules of the     |
   |                      |         | forwarding policy. For details, see   |
   |                      |         | :ref:`sl7pc_t6`.                      |
   +----------------------+---------+---------------------------------------+
   | position             | Integer | Specifies the forwarding priority.    |
   |                      |         | The value ranges from **1** to        |
   |                      |         | **100**. The default value is         |
   |                      |         | **100**.                              |
   |                      |         |                                       |
   |                      |         | This parameter is reserved.           |
   +----------------------+---------+---------------------------------------+
   | provisioning_status  | String  | This parameter is reserved, and its   |
   |                      |         | value can only be **ACTIVE**.         |
   |                      |         |                                       |
   |                      |         | It specifies the provisioning status  |
   |                      |         | of the forwarding policy.             |
   +----------------------+---------+---------------------------------------+

.. _sl7pu_t6:
.. table:: **Table 6** **rules** parameter description

   ========= ====== ===============================================================
   Parameter Type   Description
   ========= ====== ===============================================================
   id        String Lists the IDs of the forwarding rules in the forwarding policy.
   ========= ====== ===============================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Updating a forwarding policy

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586

      {
          "l7policy": {
              "name": "test"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "l7policy": {
              "redirect_pool_id": "431a03eb-81bb-408e-ae37-7ce19023692b",
              "redirect_listener_id": null,
              "description": "",
              "admin_state_up": true,
              "rules": [
                  {
                      "id": "67d8a8fa-b0dd-4bd4-a85b-671db19b2ef3"
                  },
                  {
                      "id": "f02b3bca-69d2-4335-a3fa-a8054e996213"
                  }
              ],

              "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",

              "listener_id": "26058b64-6185-4e06-874e-4bd68b7633d0",
              "redirect_url": null,
              "action": "REDIRECT_TO_POOL",
              "provisioning_status": "ACTIVE",
              "position": 2,
              "id": "5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586",
              "name": "test"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Forwarding Policy
============================

Function
^^^^^^^^

This API is used to delete a specific forwarding policy.

URI
^^^

DELETE /v2.0/lbaas/l7policies/{l7policy_id}

.. table:: **Table 1** Parameter description

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   l7policy_id Yes       Object Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Deleting a forwarding policy

   .. code::

      DELETE https://{Endpoint}/v2.0/lbaas/l7policies/5ae0e1e7-5f0f-47a1-b39f-5d4c428a1586

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.
