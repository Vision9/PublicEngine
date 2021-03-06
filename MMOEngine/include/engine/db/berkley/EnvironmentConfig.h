/*
 * EnvironmentConfig.h
 *
 *  Created on: 13/02/2010
 *      Author: victor
 */

#ifndef ENVIRONMENTCONFIG_H_
#define ENVIRONMENTCONFIG_H_

#include "system/platform.h"
#include <db.h>

namespace engine {
  namespace db {
    namespace berkley {

	class LockDetectMode {
	public:
		const static uint32 DEFAULT = DB_LOCK_DEFAULT;
		const static uint32 EXPIRE = DB_LOCK_EXPIRE;
		const static uint32 MAXLOCKS = DB_LOCK_MAXLOCKS;
		const static uint32 MAXWRITE = DB_LOCK_MAXWRITE;
		const static uint32 MINLOCKS = DB_LOCK_MINLOCKS;
		const static uint32 MINWRITE = DB_LOCK_MINWRITE;
		//const static uint32 NONE = DB_LOCK_NONE;
		const static uint32 OLDEST = DB_LOCK_OLDEST;
		const static uint32 RANDOM = DB_LOCK_RANDOM;
		const static uint32 YOUNGEST = DB_LOCK_YOUNGEST;
	};

	class EnvironmentConfig {
		uint32 environmentFlags;
		uint32 threadCount;
		uint32 lockDetectMode;
		bool logAutoRemove;
		int maxLogFileSize;

	public:
		static EnvironmentConfig DEFAULT;

	public:
		EnvironmentConfig() {
			environmentFlags = 0;
			threadCount = 0;
			logAutoRemove = false;
			lockDetectMode = LockDetectMode::DEFAULT;
			maxLogFileSize = 10000; //10mb
		}


		inline void setAllowCreate(bool allowCreate) {
			if (!allowCreate)
				environmentFlags &= ~DB_CREATE;
			else
				environmentFlags |= DB_CREATE;
		}

		inline void setInitializeLocking(bool initializeLocking) {
			if (!initializeLocking)
				environmentFlags &= ~DB_INIT_LOCK;
			else
				environmentFlags |= DB_INIT_LOCK;
		}

		inline void setInitializeLogging(bool initializeLogging) {
			if (!initializeLogging)
				environmentFlags &= ~DB_INIT_LOG;
			else
				environmentFlags |= DB_INIT_LOG;
		}

		inline void setLogAutoRemove(bool logAutoRemove) {
			this->logAutoRemove = logAutoRemove;
		}

		inline void setMaxLogFileSize(int maxLogFileSize) {
			this->maxLogFileSize = maxLogFileSize;
		}

		inline void setThreaded(bool threaded) {
			if (!threaded)
				environmentFlags &= ~DB_THREAD;
			else
				environmentFlags |= DB_THREAD;
		}

		inline void setLockDetectMode(uint32 mode) {
			lockDetectMode = mode;
		}

		inline void setThreadCount(int count) {
			threadCount = count;
		}

		inline void setTransactional(bool transactional) {
			if (!transactional)
				environmentFlags &= ~DB_INIT_TXN;
			 else
				environmentFlags |= DB_INIT_TXN;
		}

		inline void setInitializeCache(bool initializeCache) {
			if (!initializeCache)
				environmentFlags &= ~DB_INIT_MPOOL;
			else
				environmentFlags |= DB_INIT_MPOOL;
		}

		inline uint32 getEnvironmentFlags() const {
			return environmentFlags;
		}

		inline uint32 getThreadCount() const {
			return threadCount;
		}

		inline uint32 getLockDetectMode() const {
			return lockDetectMode;
		}

		inline int getMaxLogFileSize() const {
			return maxLogFileSize;
		}

		inline bool getLogAutoRemove() const {
			return logAutoRemove;
		}

	};

    } // namespace berkley
  } // namespace db
} // namespace engine

#endif /* ENVIRONMENTCONFIG_H_ */
